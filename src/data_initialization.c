#include "../philosophers_general.h"

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ph_calloc(data->amount_philo + 1, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (ph_putendl_fd(ERR_MEM, 2), 1);
	while (i < data->amount_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	create_philosophers_squad(t_data *data)
{
	int	i;

	i = 0;
	data->philo = ph_calloc(data->amount_philo + 1, sizeof(t_philo));
	if (!data->philo)
		return (ph_putendl_fd(ERR_MEM, 2), NULL);
	while (i < data->amount_philo)
	{
		data->philo[i].philo_nb = i + 1;
		data->philo[i].state = THINK;
		i++;
	}
	return (0);
}

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = ph_calloc(1, sizeof(t_data));
	if (!data)
		return (ph_putendl_fd(ERR_MEM, 2), NULL);
	data->amount_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atol(argv[2]);
	data->time_to_eat = ph_atol(argv[3]);
	data->time_to_sleep = ph_atol(argv[4]);
	data->nb_of_meal = ph_atol(argv[5]);
	if (create_philosophers_squad(data) == 1)
		return (free_memory(data), NULL);
	if (create_forks(data) == 1)
		return (dinner_is_over(data), NULL);
	return (data);
}
