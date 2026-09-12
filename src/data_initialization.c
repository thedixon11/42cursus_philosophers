#include "../philosophers_general.h"

int create_data_mutexes(t_data *data)
{
	pthread_mutex_init(&data->mtx_amount_philo, NULL);
	pthread_mutex_init(&data->mtx_time_to_die, NULL);
	pthread_mutex_init(&data->mtx_time_to_eat, NULL);
	pthread_mutex_init(&data->mtx_time_to_sleep, NULL);
	pthread_mutex_init(&data->mtx_nb_of_meal, NULL);
	pthread_mutex_init(&data->mtx_printer, NULL);
	pthread_mutex_init(&data->mtx_does_sejour_over, NULL);
}

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ph_calloc(data->amount_philo + 1, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (free_memory(data), ph_putendl_fd(ERR_MEM, 2), 1);
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
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].nb_of_meal = data->nb_of_meal;
		i++;
	}
	return (0);
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = ph_calloc(1, sizeof(t_data));
	if (!data)
		return (ph_putendl_fd(ERR_MEM, 2), NULL);
	data->amount_philo = ph_atoi(argv[1]);
	data->time_to_die = ph_atol(argv[2]);
	data->time_to_eat = ph_atol(argv[3]);
	data->time_to_sleep = ph_atol(argv[4]);
	if (argc == 5)
	  data->nb_of_meal = ph_atol(argv[5]);
	else
    data->nb_of_meal = -1;
	data->does_sejour_over = false;
	if (create_philosophers_squad(data) == 1)
		return (free_memory(data), NULL);
	if (create_forks(data) == 1)
		return (NULL);
	create_data_mutexes(data);
	return (data);
}
