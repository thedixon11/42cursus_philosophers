#ifndef PHILOSOPHERS_GENERAL_H
# define PHILOSOPHERS_GENERAL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>
# include <string.h>
# include "./philosophers_struct.h"
# include "./src/utils/philosophers_utils.h"

// Lists of log messages
# define LOG_FORK "has taken a fork\n"
# define LOG_EAT "is eating\n"
# define LOG_SLEEP "is sleeping\n"
# define LOG_THINK "is thinking\n"
# define LOG_DEAD "died\n"

//Lists of errors
# define ERR_NUM "Capi wants only numbers as program args. Nothing else."
# define ERR_MINMAX "Capi wants only numbers between 0 and 2147483647. Last time you do this!!"
# define ERR_ARGS \
	"Capi wants between 4 and 5 args:\n" \
	"\t1) number_of_philosophers\n" \
	"\t2) time to die\n" \
	"\t3) time to eat\n" \
	"\t4) time to sleep\n" \
	"\t5) (optional) number of times each philosopher must eat\n"
# define ERR_MEM "Capi failed to allocate memory."
# define ERR_NBPHILO "Capi wants to invite at least one person to dinner.\n"
# define ERR_TIME "Capi had an issue with gettimeofday"
# define ERR_PRINTF "Capi had an issue with printf"
# define ERR_FULL "Nobody is hungry. Lets do the fondue another day\n"

// main.c
void	set_lr_forks(t_capi *capi);

// check_values_are_right.c
int		check_values_are_right(int argc, char **argv);
int		check_all_is_digit(char **argv, int	y);

// data_initialization.c
t_capi	*init_capi_forks_philos(int argc, char **argv);
int		create_philosophers_squad(t_capi *capi);
int		create_forks(t_capi *capi);
void	create_capi_mutexes(t_capi *capi);

// sejour_at_chalet.c
void	*sejour_at_chalet(void *item);
void	snoring_time(t_philo *philo);
void	fondue_time(t_philo *philo);

// sejour_at_chalet_utils.c
int		pick_up_forks(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2);
int	action_by_usleep(t_philo *philo, long time_of_action);
bool	does_sejour_over(t_philo *philo);
long	ask_capi_the_time(void);
int	philos_printer(t_philo *philo, char *message);

// capis_desk.c
void	*capi_the_butler(t_capi *capi);
bool  does_capi_close_chalet(t_capi *capi);
bool  check_if_someone_starved(t_capi *capi);
bool  check_if_everyone_is_full(t_capi *capi);
void	capis_printer(t_capi *capi, char *message);

// dinner_is_over.c
void	dinner_is_over(t_capi *capi);
void	join_all_threads(t_capi *capi);
void	destroy_all_mutexes(t_capi *capi);
void	free_memory(t_capi *capi);

// error_inside_routine.c
void  error_inside_routine_capi(t_capi *capi, char *message);
void  error_inside_routine(t_philo *philo, char *message);

#endif
