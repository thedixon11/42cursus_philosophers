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
  int i;

  i = 0;
  while (i < data->amount_philo)
  {
    pthread_mutex_destroy(&data->forks[i]);
    i++;
  }
  pthread_mutex_destroy(&data->mtx_amount_philo);
  pthread_mutex_destroy(&data->mtx_time_to_die);
  pthread_mutex_destroy(&data->mtx_time_to_eat);
  pthread_mutex_destroy(&data->mtx_time_to_sleep);
  pthread_mutex_destroy(&data->mtx_nb_of_meal);
  pthread_mutex_destroy(&data->mtx_printer);
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
