#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

typedef enum e_fork
{
	FORK,
	NO_FORK
}

typedef	enum e_state
{
	S_EAT,
	S_SLEEP,
	S_THINK,
	S_DEAD
}			t_state;

typedef struct s_philo
{
	int			philo_nb;
	t_state		state;
	suseconds_t	eat_time;
	suseconds_t	sleep_time;
}				t_philo

typedef struct s_data
{
	int		amount_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		nb_of_meal;
	int		*forks;
	t_philo	*philo;
}			t_data;

#endif
