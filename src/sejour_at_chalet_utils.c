#include "../philosophers_general.h"

void  philos_printer(t_philo *philo, char *message)
{
	long	time_to_print;
	long	last_action_time;
	long	last_meal_time;

	if (does_sejour_over(philo) == true)
		return ;
	last_action_time = ask_capi_the_time();
	if (philo->state == EAT)
	{
		last_meal_time = last_action_time;
		pthread_mutex_lock(&philo->mtx_last_meal_time);
		philo->last_meal_time = last_meal_time;
		pthread_mutex_unlock(&philo->mtx_last_meal_time);
		pthread_mutex_lock(&philo->mtx_meal_ate);
		philo->meal_ate++;
		pthread_mutex_unlock(&philo->mtx_meal_ate);
	}
	time_to_print = last_action_time - philo->start_time;
	pthread_mutex_lock(philo->mtx_printer);
	printf("%ld %d %s", time_to_print, philo->philo_nb, message);
	pthread_mutex_unlock(philo->mtx_printer);
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
	if (gettimeofday(&tv, NULL) == -1)
		return (ph_putendl_fd(strerror(errno), 2), -1);
	seconds = tv.tv_sec;
	microseconds = tv.tv_usec;
	milliseconds = (seconds * 1000) + (microseconds / 1000);
	return (milliseconds);
}

bool	does_sejour_over(t_philo *philo)
{
	bool	answer;

	answer = false;
	pthread_mutex_lock(philo->mtx_does_sejour_over);
	answer = *(philo->does_sejour_over);
	pthread_mutex_unlock(philo->mtx_does_sejour_over);
	return (answer);
}

void	action_by_usleep(t_philo *philo, long time_of_action)
{
	long	current_time;
	long	end;

	current_time = 0;
	if (does_sejour_over(philo) == true)
		return ;
	end = ask_capi_the_time() + time_of_action;
	while (current_time < end)
	{
		usleep(100);
		current_time = ask_capi_the_time();
		if (does_sejour_over(philo) == true)
			break ;
	}
}

int	pick_up_forks(t_philo *philo, pthread_mutex_t *f1, pthread_mutex_t *f2)
{
    pthread_mutex_lock(f1);
    philos_printer(philo, LOG_FORK);
    if (philo->amount_philo == 1)
    {
      while (does_sejour_over(philo) != true)
        usleep(10);
      return (1);
    }
    pthread_mutex_lock(f2);
    philos_printer(philo, LOG_FORK);
	return (0);
}
