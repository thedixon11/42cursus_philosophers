#include "../philosophers_general.h"

int	create_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = ph_calloc(data->amount_philo, sizeof(int));
	if (!data->forks)
		return (ph_putendl_fd(ERR_MEM, 2), 1);
	while (i < data->amount_philo)
	{
		data->forks[i] = FREE;
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
		data->philo[i].philo_nb = i;
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
	if (create_forks(data) == 1)
		return (dinner_is_over(data), NULL);
	if (create_philosophers_squad(data) == 1)
		return (dinner_is_over(data), NULL);
	if (create_)
	return (data);
}

int	check_values_are_right(char **argv)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (argv[y] != NULL)
	{
		while (argv[y][x] != NULL)
		{
			if (ph_isdigit(argv[y][x] != 1))
				return (ph_putendl_fd(ERR_NUM, 2), 1);
			if ((ph_atol(argv[y][x]) < INT_MIN) || (ph_atol(argv[y][x]) > INT_MAX))
				return (ph_putendl_fd(ERR_MINMAX, 2), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int	i;

	i = 0;
	if ((argc != 4) || (argc != 5))
		return (ph_putendl_fd(ERR_ARGS, 2), 1);
	if (check_values_are_right(argv) == 1)
		return (1);
	data = init_data(argv);
	if (!data)
		return (1);
	while (i < data->amount_philo)
	{
		pthread_create(&data->philo[i].id, NULL, &start_the_meal, data);
		i++;
	}
}
