*This project has been created as part of the 42 curriculum by jvasconc.*

# 🍽️ Philosophers

> Threads, mutexes, and a table full of hungry philosophers who really need to stop
> starving.

## Table of Contents

- [Description](#description)
- [Technical Choices](#technical-choices)
- [Instructions](#instructions)
  - [Compilation](#compilation)
  - [Usage](#usage)
  - [Examples](#examples)
  - [Checking for data races](#checking-for-data-races)
- [Resources](#resources)

## Description

This is the mandatory part of 42's **Philosophers** project, an exercise in concurrent
programming built around the classic *Dining Philosophers* problem (E. W. Dijkstra,
1965).

`N` philosophers sit around a round table. Between each pair of them lies a single fork
— so there are exactly `N` forks for `N` philosophers. Each philosopher repeats the same
cycle forever: **think → eat → sleep → think → ...**. To eat, a philosopher must hold
*both* the fork on their left and the fork on their right at the same time. If a
philosopher goes too long without eating, they die — and the simulation must report that
death almost instantly.

The challenge isn't the loop itself, it's making all of this happen **safely** across
multiple threads sharing the same forks, the same clock, and the same standard output —
without deadlocks, without starvation, and without a single data race.

## Technical Choices

| Concern | Approach |
|---|---|
| Concurrency model | One `pthread` per philosopher |
| Forks | One `pthread_mutex_t` per fork, shared between two neighboring philosophers |
| Death / end-of-simulation detection | A separate monitor ("butler") thread polling meal times and meal counts |
| Shared state protection | Individual mutexes for: each fork, each philosopher's last-meal-time, each philosopher's meal counter, the shared stop flag, and stdout (printer) |
| Stopping condition | Shared `does_sejour_over` boolean, guarded by its own mutex and checked before/after every blocking or timed action |
| Odd fork-order deadlock avoidance | Even-numbered and odd-numbered philosophers pick up forks in opposite order (right-then-left vs left-then-right) |

Data races were hunted down and eliminated using `valgrind --tool=helgrind`.

## Instructions

### Compilation

```bash
git clone <your_repo_url>
cd philo
make
```

Available Makefile targets: `all`, `clean`, `fclean`, `re`, `$(NAME)`.

### Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Argument | Unit | Meaning |
|---|---|---|
| `number_of_philosophers` | count | Number of philosophers **and** forks |
| `time_to_die` | ms | Time without eating before a philosopher dies |
| `time_to_eat` | ms | Time spent eating (forks held) |
| `time_to_sleep` | ms | Time spent sleeping |
| `number_of_times_each_philosopher_must_eat` | count (optional) | Simulation stops once every philosopher reaches this meal count |

### Examples

```bash
./philo 5 800 200 200        # runs until someone starves
./philo 4 410 200 200 7      # stops once everyone has eaten 7 times
./philo 1 800 200 200        # single philosopher: dies (only one fork available)
```

### Checking for data races

```bash
valgrind --tool=helgrind ./philo 4 2000 1000 1000
```

Use generous timing arguments under Valgrind — instrumentation overhead can otherwise
cause philosophers to "starve" purely because of the tool's slowdown, not a real bug.

## Resources

- 42 School subject — *Philosophers*
- E. W. Dijkstra, *Hierarchical ordering of sequential processes* (1971) — the original
  dining philosophers formulation
- `man pthread_create` / `pthread_join` / `pthread_mutex_init` / `pthread_mutex_lock` /
  `pthread_mutex_unlock` / `gettimeofday`
- [Valgrind Helgrind manual](https://valgrind.org/docs/manual/hg-manual.html)

**AI usage:** AI (Claude) was used purely as a debugging and review assistant, not to
generate the project's core logic:
- Diagnosing a Helgrind-reported data race: `join_all_threads` was iterating up to
  `capi->created_threads`, a counter that was only ever set on the thread-creation
  *failure* path and therefore stayed at `0` on success — so threads were never joined
  before mutexes were destroyed and memory freed.
- Discussing ways to reduce Valgrind/Helgrind's runtime overhead during testing (larger
  timing arguments, fewer `usleep`/`gettimeofday` calls in the wait loop) without
  altering the simulation's actual behavior.

Every suggestion was reviewed and understood before being applied.
