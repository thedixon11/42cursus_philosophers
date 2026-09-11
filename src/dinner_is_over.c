#include "../philosophers_general.h"


void	free_memory(t_data *data)
{
	if (data->forks)
		ph_free((void **)&data->forks);
	if (data->philo)
		ph_free((void **)&data->philo);
	if (data)
		ph_free((void **)&data);
}

void	destroy_all_mutexes(t_data *data)
{

}

void	join_all_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		pthread_join(&data->philo[i].id, NULL);
		i++;
	}
}

void	dinner_is_over(t_data *data)
{
	destroy_all_mutexes(data);
	free_memory(data);
}
