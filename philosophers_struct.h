#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

typedef enum e_state
{
	EAT,
	SLEEP,
	THINK
}						t_state;

typedef struct s_philo
{
	pthread_t				id;
	int					philo_nb;
	t_state				state;
	long				start_time;
	long				time_to_eat;
	long				time_to_sleep;
	long				last_meal_time;
	pthread_mutex_t		mtx_last_meal_time;
	long				last_action_time;
	pthread_mutex_t		mtx_last_action_time;
	int					meal_ate;
	pthread_mutex_t		mtx_meal_ate;
	bool				*does_sejour_over;
	pthread_mutex_t		*mtx_does_sejour_over;
	pthread_mutex_t		*mtx_printer;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
}						t_philo;

typedef struct s_capi
{
	int					amount_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					meals_to_eat;
	bool				does_someone_died;
	int					whos_dead;
	t_philo				*philo;
	bool				does_sejour_over;
	pthread_mutex_t		mtx_does_sejour_over;
	pthread_mutex_t		mtx_printer;
	pthread_mutex_t		*forks;
}						t_capi;

#endif
