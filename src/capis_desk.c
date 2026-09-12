#include "../philosophers_general.h"

bool	does_sejour_over(t_philo *philo)
{
	bool	answer;

	answer = false;
	pthread_mutex_lock(philo->mtx_does_sejour_over);
	if (*does_sejour_over == true)
		answer = true;
	pthread_mutex_unlock(philo->mtx_does_sejour_over);
	return (answer);
}

long	ask_capi_the_time(void)
{
	long	seconds;
	long	milliseconds;
	long	microseconds;
	struct timeval	tv;

	seconds = 0;
	milliseconds = 0;
	microseconds = 0;
	if (gettimeofday(tv, NULL) == -1)
		return (ph_putendl_fd(strerror(errno), 2), -1);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	milliseconds = (seconds * 1000) + (milliseconds / 1000);
	return (milliseconds);
}

void  philos_printer(t_philo philo, char *message)
{
	pthread_mutex_lock(philo.mtx_printer);
	pthread_mutex_lock(philo.mtx_last_action_time);
	philo.last_action_time = ask_capi_the_time();
	if (philo->state == EAT)
		philo.mtx_last_meal_time = philo.last_action_time;
	printf("%d %d %s", philo.last_action_time, philo.philo_nb, message);
	pthread_mutex_unlock(philo.mtx_last_action_time);
	pthread_mutex_unlock(philo.mtx_printer);
}

void	capis_printer(t_data *data, char *message)
{

}

void	*capi_the_butler(t_data *data)
{

}
