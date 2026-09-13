#include "../philosophers_general.h"

void	define_lr_fork_n_printer(t_capi *capi)
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
		capi->philo[i].mtx_printer = &capi->mtx_printer;
		capi->philo[i].mtx_does_sejour_over = &capi->mtx_does_sejour_over;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_capi	*capi;
	int	i;

	i = 0;
	if ((argc != 4) || (argc != 5))
		return (ph_putendl_fd(ERR_ARGS, 2), 1);
	if (check_values_are_right(argv) == 1)
		return (1);
	capi = init_capi(argc, argv);
	if (!capi)
		return (1);
	define_lr_fork(capi);
	while (i < capi->amount_philo)
	{
    capi->philo[i].start_time = ask_capi_the_time(); 
		pthread_create(&capi->philo[i].id, NULL, &sejour_at_chalet, &capi->philo[i]);
		i++;
	}
	//pthread_create(&capi->capibara, NULL, &capi_the_butler, capi);
	dinner_is_over(capi);
	return (0);
}
