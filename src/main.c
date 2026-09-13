#include "../philosophers_general.h"

void	define_lr_fork_n_printer(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->amount_philo)
	{
		data->philo[i].right_fork = &data->forks[i];
		if (i == 0)
			data->philo[i].left_fork = &data->forks[data->amount_philo - 1];
		else
			data->philo[i].left_fork = &data->forks[i - 1];
		data->philo[i].mtx_printer = &data->mtx_printer;
		data->philo[i].mtx_does_sejour_over = &data->mtx_does_sejour_over;
		i++;
	}
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
	data = init_data(argc, argv);
	if (!data)
		return (1);
	define_lr_fork(data);
	while (i < data->amount_philo)
	{
    data->philo[i].start_time = ask_capi_the_time(); 
		pthread_create(&data->philo[i].id, NULL, &sejour_at_chalet, &data->philo[i]);
		i++;
	}
	//pthread_create(&data->capibara, NULL, &capi_the_butler, data);
	dinner_is_over(data);
	return (0);
}
