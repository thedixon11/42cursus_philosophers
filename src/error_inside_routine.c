/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_inside_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:58:55 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 09:58:56 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_general.h"

void	error_inside_routine_capi(t_capi *capi, char *message)
{
	pthread_mutex_lock(&capi->mtx_does_sejour_over);
	capi->does_sejour_over = true;
	pthread_mutex_unlock(&capi->mtx_does_sejour_over);
	pthread_mutex_lock(&capi->mtx_printer);
	printf("%s", message);
	pthread_mutex_unlock(&capi->mtx_printer);
}

void	error_inside_routine(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->mtx_does_sejour_over);
	*philo->does_sejour_over = true;
	pthread_mutex_unlock(philo->mtx_does_sejour_over);
	pthread_mutex_lock(philo->mtx_printer);
	printf("%s", message);
	pthread_mutex_unlock(philo->mtx_printer);
}
