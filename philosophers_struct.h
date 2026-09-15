/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:59:14 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 09:59:16 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
}					t_state;

typedef struct s_philo
{
	pthread_t		id;
	int				philo_nb;
	t_state			state;
	long			start_time;
	int				amount_philo;
	long			time_to_eat;
	long			time_to_sleep;
	long			last_meal_time;
	pthread_mutex_t	mtx_last_meal_time;
	int				meal_ate;
	pthread_mutex_t	mtx_meal_ate;
	bool			*does_sejour_over;
	pthread_mutex_t	*mtx_does_sejour_over;
	pthread_mutex_t	*mtx_printer;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

typedef struct s_capi
{
	int				amount_philo;
	int				created_threads;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				meals_to_eat;
	int				whos_dead;
	long			time_of_death;
	t_philo			*philo;
	bool			does_sejour_over;
	pthread_mutex_t	mtx_does_sejour_over;
	pthread_mutex_t	mtx_printer;
	pthread_mutex_t	*forks;
}					t_capi;

#endif
