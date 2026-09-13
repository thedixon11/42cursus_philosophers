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

}

bool  check_if_someone_is_full(t_capi *capi)
{

}
bool  check_if_someone_starved(t_capi *capi)
{

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
      capis_printer(capi,)
      dinner_is_over(capi);
      break ;
    }
  }
}
