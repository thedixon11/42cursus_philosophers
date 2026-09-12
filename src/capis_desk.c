#include "../philosophers_general.h"

void  philos_printer(t_philo philo, char *message)
{
	pthread_mutex_lock(philo.mtx_printer);
	pthread_mutex_lock(philo.mtx_last_action_time);
	printf("%d %d %s", philo.last_action_time, philo.philo_nb, message);
	pthread_mutex_unlock(philo.mtx_last_action_time);
	pthread_mutex_unlock(philo.mtx_printer);
}

void	capis_printer(t_data *data, char *message)
{

}

void	*capi_the_butler(t_data *data)
{

}:while
