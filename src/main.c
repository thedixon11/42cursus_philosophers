#include "../philosophers_general.h"

void	define_stoled_fork(t_data *data)
{
	int	i;

	i = 0;
	while ((i + 1) < data->amount_philo)
	{
		data->philo[i].my_fork = &data->forks[i];
		data->philo[i].stoled_fork = &data->forks[i + 1];
		i++;
		data->philo[i].my_fork = &data->forks[i];
		data->philo[i].stoled_fork = &data->forks[i - 1];
		i++;
	}
	data->philo[i].my_fork = &
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
	define_stoled_fork(data);
	while (i < data->amount_philo)
	{
		pthread_create(&data->philo[i].id, NULL, &start_the_meal, data);
		i++;
	}
	i = 0;
	dinner_is_over(data);
	return (0);
}
