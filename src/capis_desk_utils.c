/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capis_desk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:29:51 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 10:33:47 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_general.h"

void	capis_printer(t_capi *capi, char *message)
{
	long	current_time;
	long	time_of_death;
	int		i;

	i = capi->whos_dead - 1;
	current_time = ask_capi_the_time();
	if (current_time == -1)
	{
		error_inside_routine_capi(capi, ERR_TIME);
		return ;
	}
	time_of_death = current_time - capi->philo[i].start_time;
	pthread_mutex_lock(&capi->mtx_printer);
	if (printf("%ld %d %s", time_of_death, capi->whos_dead, message) < 0)
		error_inside_routine_capi(capi, ERR_PRINTF);
	pthread_mutex_unlock(&capi->mtx_printer);
}

int	capis_starter(t_capi *capi)
{
	long	current_time;

	current_time = 0;
	while (current_time < capi->start_time)
	{
		current_time = ask_capi_the_time();
		if (current_time == -1)
			return (error_inside_routine_capi(capi, ERR_TIME), 1);
	}
	return (0);
}
