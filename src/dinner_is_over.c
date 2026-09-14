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
		pthread_mutex_destroy(&capi->philo[i].mtx_last_meal_time);
		pthread_mutex_destroy(&capi->philo[i].mtx_meal_ate);
		i++;
	}
	pthread_mutex_destroy(&capi->mtx_printer);
	pthread_mutex_destroy(&capi->mtx_does_sejour_over);
}

void	join_all_threads(t_capi *capi)
{
	int	i;

	i = 0;
	while (i < capi->created_threads)
	{
		pthread_join(capi->philo[i].id, NULL);
		i++;
	}
}

void	dinner_is_over(t_capi *capi)
{
	join_all_threads(capi);
	destroy_all_mutexes(capi);
	free_memory(capi);
}
