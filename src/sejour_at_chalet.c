#include "../philosophers_general.h"

void	action_by_usleep(t_philo *philo, long time_of_action)
{
	long	current_time;
	long	end;

	current_time = 0;
	end = ask_capi_the_time() + time_of_action;
	while (current_time < end && does_sejour_over(philo) == false)
	{
		usleep(500);
		current_time = ask_capi_the_time();
	}
}

void	pick_up_forks(t_philo *philo, pthread_mutex *f1, pthread_mutex *f2)
{
    pthread_mutex_lock(f1, NULL);
    philos_printer(philo, LOG_FORK);
    pthread_mutex_lock(f2, NULL);
    philos_printer(philo, LOG_FORK);
}

void  fondue_time(t_philo *philo)
{
	if (philo->philo_nb % 2 == 1)
		pick_up_forks(philo, philo->right_fork, philo->left_fork);
	else
		pick_up_forks(philo, philo->left_fork, philo->right_fork);
	philo->state = EAT;
  philos_printer(philo, LOG_EAT);
	action_by_usleep(philo, philo->eat_time);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
  philo->state = THINK;
	philos_printer(philo, LOG_THINK);
}

void  snoring_time(t_philo *philo)
{
	philo->state = SLEEP;
  philos_printer(philo, LOG_SLEEP);
  action_by_usleep(philo, philo->time_to_sleep);
  philo->state = THINK;
  philos_printer(philo, LOG_THINK);
}

void	*sejour_at_chalet(t_philo *philo)
{
  while (does_sejour_over(philo) == false)
  {
    if (does_sejour_over(philo == false))
      fondue_time(philo);
    if (does_sejour_over(philo == false))
      snoring_time(philo);
  }
}
