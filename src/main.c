/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:58:18 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 09:58:25 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_general.h"

void	set_lr_forks(t_capi *capi)
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
		i++;
	}
}

int	create_threads(t_capi *capi)
{
	int		i;
	long	start_time;

	i = 0;
	start_time = ask_capi_the_time();
	if (start_time == -1)
		return (ph_putendl_fd(ERR_TIME, 2), 1);
	start_time += 1000;
	while (i < capi->amount_philo)
	{
		capi->philo[i].start_time = start_time;
		capi->philo[i].last_meal_time = capi->philo[i].start_time;
		if (pthread_create(&capi->philo[i].id, NULL, &sejour_at_chalet,
				&capi->philo[i]) != 0)
		{
			capi->created_threads = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_capi	*capi;
	int		error;

	error = 0;
	if (argc < 5 || argc > 6)
		return (ph_putendl_fd(ERR_ARGS, 2), 1);
	if (check_values_are_right(argc, argv) == 1)
		return (1);
	capi = init_capi_forks_philos(argc, argv);
	if (!capi)
		return (1);
	set_lr_forks(capi);
	error = create_threads(capi);
	if (error == 0)
		capi_the_butler(capi);
	dinner_is_over(capi);
	return (0);
}
