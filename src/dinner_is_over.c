#include "../philosophers_general.h"

void	dinner_is_over(t_data *data)
{
	if (data->forks)
		ph_free((void **)&data->forks);
	if (data->philo)
		ph_free((void **)&data->philo);
	if (data)
		ph_free((void **)&data);
}
