#include "../philosophers_general.h"

int create_capi_mutexes(t_capi *capi)
{
	pthread_mutex_init(&capi->mtx_amount_philo, NULL);
	pthread_mutex_init(&capi->mtx_time_to_die, NULL);
	pthread_mutex_init(&capi->mtx_time_to_eat, NULL);
	pthread_mutex_init(&capi->mtx_time_to_sleep, NULL);
	pthread_mutex_init(&capi->mtx_nb_of_meal, NULL);
	pthread_mutex_init(&capi->mtx_printer, NULL);
	pthread_mutex_init(&capi->mtx_does_sejour_over, NULL);
}

int	create_forks(t_capi *capi)
{
	int	i;

	i = 0;
	capi->forks = ph_calloc(capi->amount_philo + 1, sizeof(pthread_mutex_t));
	if (!capi->forks)
		return (free_memory(capi), ph_putendl_fd(ERR_MEM, 2), 1);
	while (i < capi->amount_philo)
	{
		pthread_mutex_init(&capi->forks[i], NULL);
		i++;
	}
	return (0);
}

int	create_philosophers_squad(t_capi *capi)
{
	int	i;

	i = 0;
	capi->philo = ph_calloc(capi->amount_philo + 1, sizeof(t_philo));
	if (!capi->philo)
		return (ph_putendl_fd(ERR_MEM, 2), NULL);
	while (i < capi->amount_philo)
	{
		capi->philo[i].philo_nb = i + 1;
		capi->philo[i].state = THINK;
		capi->philo[i].time_to_die = capi->time_to_die;
		capi->philo[i].time_to_eat = capi->time_to_eat;
		capi->philo[i].time_to_sleep = capi->time_to_sleep;
		capi->philo[i].nb_of_meal = capi->nb_of_meal;
		i++;
	}
	return (0);
}

t_capi	*init_capi(int argc, char **argv)
{
	t_capi	*capi;

	capi = ph_calloc(1, sizeof(t_capi));
	if (!capi)
		return (ph_putendl_fd(ERR_MEM, 2), NULL);
	capi->amount_philo = ph_atoi(argv[1]);
	capi->time_to_die = ph_atol(argv[2]);
	capi->time_to_eat = ph_atol(argv[3]);
	capi->time_to_sleep = ph_atol(argv[4]);
	if (argc == 5)
	  capi->nb_of_meal = ph_atol(argv[5]);
	else
    capi->nb_of_meal = -1;
	capi->does_sejour_over = false;
	if (create_philosophers_squad(capi) == 1)
		return (free_memory(capi), NULL);
	if (create_forks(capi) == 1)
		return (NULL);
	create_capi_mutexes(capi);
	return (capi);
}
