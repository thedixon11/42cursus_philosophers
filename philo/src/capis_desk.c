/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capis_desk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:58:32 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 10:33:58 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_general.h"

bool	check_if_everyone_is_full(t_capi *capi)
{
	int		i;
	bool	answer;

	i = 0;
	answer = true;
	if (capi->meals_to_eat == -1)
		return (false);
	while (i < capi->amount_philo)
	{
		pthread_mutex_lock(&capi->philo[i].mtx_meal_ate);
		if (capi->philo[i].meal_ate < capi->meals_to_eat)
			answer = false;
		pthread_mutex_unlock(&capi->philo[i].mtx_meal_ate);
		if (answer == false)
			break ;
		i++;
	}
	return (answer);
}

bool	check_if_someone_starved(t_capi *capi)
{
	int		i;
	long	current_time;
	long	last_meal_time;

	i = 0;
	current_time = 0;
	last_meal_time = 0;
	while (i < capi->amount_philo)
	{
		current_time = ask_capi_the_time();
		if (current_time == -1)
			return (error_inside_routine_capi(capi, ERR_TIME), true);
		pthread_mutex_lock(&capi->philo[i].mtx_last_meal_time);
		last_meal_time = capi->philo[i].last_meal_time;
		pthread_mutex_unlock(&capi->philo[i].mtx_last_meal_time);
		if ((current_time - last_meal_time) > capi->time_to_die)
		{
			capi->whos_dead = capi->philo[i].philo_nb;
			capis_printer(capi, LOG_DEAD);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	does_capi_close_chalet(t_capi *capi)
{
	if (check_if_someone_starved(capi) == true)
		return (true);
	if (check_if_everyone_is_full(capi) == true)
		return (true);
	return (false);
}

void	*capi_the_butler(t_capi *capi)
{
	bool	does_sejour_over;

	does_sejour_over = false;
	if (capis_starter(capi) == 1)
		return (NULL);
	while (1)
	{
		if (does_capi_close_chalet(capi) == true || does_sejour_over == true)
		{
			pthread_mutex_lock(&capi->mtx_does_sejour_over);
			capi->does_sejour_over = true;
			pthread_mutex_unlock(&capi->mtx_does_sejour_over);
			usleep(5000);
			break ;
		}
		pthread_mutex_lock(&capi->mtx_does_sejour_over);
		does_sejour_over = capi->does_sejour_over;
		pthread_mutex_unlock(&capi->mtx_does_sejour_over);
	}
	return (NULL);
}
