#include "../philosophers_general.h"

void	free_memory(t_capi *capi)
{
	if (capi->forks)
		ph_free((void **)&capi->forks);
	if (capi->philo)
		ph_free((void **)&capi->philo);
	if (capi)
		ph_free((void **)&capi);
}

void	destroy_all_mutexes(t_capi *capi)
{
	int i;

	i = 0;
	while (i < capi->amount_philo)
	{
	pthread_mutex_destroy(&capi->forks[i]);
	i++;
	}
	pthread_mutex_destroy(&capi->mtx_amount_philo);
	pthread_mutex_destroy(&capi->mtx_time_to_die);
	pthread_mutex_destroy(&capi->mtx_time_to_eat);
	pthread_mutex_destroy(&capi->mtx_time_to_sleep);
	pthread_mutex_destroy(&capi->mtx_nb_of_meal);
	pthread_mutex_destroy(&capi->mtx_printer);
}

void	join_all_threads(t_capi *capi)
{
	int	i;

	i = 0;
	while (i < capi->amount_philo)
	{
		pthread_join(&capi->philo[i].id, NULL);
		i++;
	}
}

void	dinner_is_over(t_capi *capi)
{
	destroy_all_mutexes(capi);
	free_memory(capi);
}
