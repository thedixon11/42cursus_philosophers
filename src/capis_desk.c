#include "../philosophers_general.h"

bool	does_sejour_over(t_philo *philo)
{
	bool	answer;

	answer = false;
	pthread_mutex_lock(philo->mtx_does_sejour_over);
	if (*does_sejour_over == true)
		answer = true;
	pthread_mutex_unlock(philo->mtx_does_sejour_over);
	return (answer);
}

long	ask_capi_the_time(void)
{
	long	seconds;
	long	milliseconds;
	long	microseconds;
	struct timeval	tv;

	seconds = 0;
	milliseconds = 0;
	microseconds = 0;
	if (gettimeofday(tv, NULL) == -1)
		return (ph_putendl_fd(strerror(errno), 2), -1);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	milliseconds = (seconds * 1000) + (microseconds / 1000);
	return (milliseconds);
}

void  philos_printer(t_philo *philo, char *message)
{
  long  time_to_print;

	pthread_mutex_lock(philo->mtx_last_action_time);
	pthread_mutex_lock(philo->mtx_last_meal_time);
	philo->last_action_time = ask_capi_the_time();
  if (philo->state == EAT)
		philo->mtx_last_meal_time = philo->last_action_time;
  time_to_print = philo.last_action_time - philo->start_time;
  pthread_mutex_unlock(philo->mtx_last_meal_time);
  pthread_mutex_unlock(philo->mtx_last_action_time);
	pthread_mutex_lock(philo.mtx_printer);
	printf("%d %d %s", time_to_print, philo.philo_nb, message);
	pthread_mutex_unlock(philo.mtx_printer);
}

void	capis_printer(t_capi *capi, char *message)
{
  long  curent_time;

  pthread_mutex_lock(&capi->mtx_printer);
  current_time = ask_capi_the_time();
  printf("%d %d %s", current_time, capi->whos_dead, message);
  pthread_mutex_unlock(&capi->mtx_printer);
}

bool  check_if_someone_is_full(t_capi *capi)
{
  int i;

  i = 0;
  if (capi->meals_to_eat == -1)
    return (false);
  while (capi->philo[i] != NULL)
  {
    pthread_mutex_lock(&capi->philo[i].mtx_meal_ate);
    if (capi->philo[i].meal_ate < capi->meals_to_eat)
      return (false);
    pthread_mutex_unlock(&capi->philo[i].mtx_meal_ate);
    i++;
  }
  return (true);
}

bool  check_if_someone_starved(t_capi *capi)
{
  int i;
  int current_time;

  i = 0;
  current_time = 0;
  while (philo[i] != NULL)
  {
    current_time = ask_capi_the_time();
    pthread_mutex_lock(&capi->philo[i].mtx_last_meal_time)
    if ((current_time - capi->philo[i].last_meal_time) > capi->time_to_die)
    {
      capi->does_someone_dies = true;
      capi->whos_dead = capi->philo[i].philo_nb;
      return (true);
    }
    pthread_mutex_unlock(&capi->philo[i].mtx_last_meal_time);
    i++;
  }
  return (false);
}

bool  does_capi_close_chalet(t_capi *capi)
{
  if (check_if_someone_starved(capi) == true)
    return (true);
  if (check_if_everyone_is_full(capi) == true)
    return (true);
  return (false);
}

void	*capi_the_butler(t_capi *capi)
{
  while (1)
  {
    if (does_capi_close_chalet(capi) == true)
    {
      capi->does_sejour_over = true;
      usleep(5000);
      if (capi->does_someone_died == true)
        capis_printer(capi, LOG_DEAD);
      dinner_is_over(capi);
      break ;
    }
  }
}
