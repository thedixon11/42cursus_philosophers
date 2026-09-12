#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

typedef	enum e_state
{
	EAT,
	SLEEP,
	THINK,
	DEAD
}			t_state;

typedef struct s_philo
{
	pthread				    id;
	int					      philo_nb;
	t_state				    state;
	long				      eat_time;
	pthread_mutex_t		mtx_eat_time;
	long				      sleep_time;
	pthread_mutex_t		mtx_sleep_time;
  int               meal_ate;
	pthread_mutex_t		mtx_meal_ate;
	p_thread_mutex_t	*right_fork;
	p_thread_mutex_t	*left_fork;
	p_thread_mutex_t	*mtx_printer;
}				t_philo;

typedef struct s_data
{
	int					      amount_philo;
	long				      time_to_die;
	long				      time_to_eat;
	long				      time_to_sleep;
	int					      nb_of_meal;
  bool              is_someone_dead;
	pthread_mutex_t		*forks;
	t_philo				    *philo;
	pthread				    capibara;
	pthread_mutex_t		mtx_amount_philo;
	pthread_mutex_t		mtx_time_to_die;
	pthread_mutex_t		mtx_time_to_eat;
	pthread_mutex_t		mtx_time_to_sleep;
	pthread_mutex_t		mtx_nb_of_meal;
  pthread_mutex_t   mtx_printer;
  pthread_mutex_t   mtx_is_someone_dead;
}			t_data;

#endif
