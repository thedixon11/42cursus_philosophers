#include "../philosophers_general.h"

void  fondue_time(t_philo *philo)
{
	if (philo->philo_nb % 2 == 1)
		pick_up_forks(philo, philo->right_fork, philo->left_fork);
	else
		pick_up_forks(philo, philo->left_fork, philo->right_fork);
	philo->state = EAT;
	philos_printer(philo, LOG_EAT);
	action_by_usleep(philo, philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void  snoring_time(t_philo *philo)
{
	philo->state = SLEEP;
	philos_printer(philo, LOG_SLEEP);
	action_by_usleep(philo, philo->time_to_sleep);
	philo->state = THINK;
	philos_printer(philo, LOG_THINK);
}

void	*sejour_at_chalet(void *item)
{
	t_philo	*philo;
	
	philo = (t_philo *)item;
	while (does_sejour_over(philo) == false)
	{
		if (does_sejour_over(philo) == false)
			fondue_time(philo);
		if (does_sejour_over(philo) == false)
			snoring_time(philo);
	}
	return (NULL);
}
