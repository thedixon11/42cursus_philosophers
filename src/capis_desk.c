#include "../philosophers_general.h"

void	capis_printer(t_capi *capi, char *message)
{
  long  current_time;
  long  time_of_death;
  int i;

  i = capi->whos_dead - 1;
  current_time = ask_capi_the_time();
  time_of_death = current_time - capi->philo[i].start_time;
  pthread_mutex_lock(&capi->mtx_printer);
  printf("%ld %d %s", time_of_death, capi->whos_dead, message);
  pthread_mutex_unlock(&capi->mtx_printer);
}

bool  check_if_everyone_is_full(t_capi *capi)
{
  int i;
	bool	answer;

  i = 0;
	answer = true;
  if (capi->meals_to_eat == -1)
    return (false);
  while (i < capi->amount_philo)
  {
    pthread_mutex_lock(&capi->philo[i].mtx_meal_ate);
    if (capi->philo[i].meal_ate < capi->meals_to_eat)
		answer = false;
    pthread_mutex_unlock(&capi->philo[i].mtx_meal_ate);
	if (answer == false)
		break ;
    i++;
  }
  return (answer);
}

bool  check_if_someone_starved(t_capi *capi)
{
  int i;
  long current_time;

  i = 0;
  current_time = 0;
  while (i < capi->amount_philo)
  {
    current_time = ask_capi_the_time();
    pthread_mutex_lock(&capi->philo[i].mtx_last_meal_time);
    if ((current_time - capi->philo[i].last_meal_time) > capi->time_to_die)
    {
      capi->does_someone_died = true;
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
			usleep(500);
			if (capi->does_someone_died == true)
				capis_printer(capi, LOG_DEAD);
			break ;
		}
	}
	return (NULL);
}
