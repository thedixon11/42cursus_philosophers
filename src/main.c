#include "../philosophers_general.h"

void	set_lr_forks(t_capi *capi)
{
	int	i;

	i = 0;
	while (i < capi->amount_philo)
	{
		capi->philo[i].right_fork = &capi->forks[i];
		if (i == 0)
			capi->philo[i].left_fork = &capi->forks[capi->amount_philo - 1];
		else
			capi->philo[i].left_fork = &capi->forks[i - 1];
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_capi	*capi;
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ph_putendl_fd(ERR_ARGS, 2), 1);
	if (check_values_are_right(argv) == 1)
		return (1);
	capi = init_capi_forks_philos(argc, argv);
	if (!capi)
		return (1);
	set_lr_forks(capi);
	while (i < capi->amount_philo)
	{
		capi->philo[i].start_time = ask_capi_the_time();
		capi->philo[i].last_meal_time = capi->philo[i].start_time;
		pthread_create(&capi->philo[i].id, NULL, &sejour_at_chalet, &capi->philo[i]);
		i++;
	}
	capi_the_butler(capi);
	dinner_is_over(capi);
	return (0);
}
