#ifndef PHILOSOPHERS_GENERAL_H
# define PHILOSOPHERS_GENERAL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "./philosophers_struct.h"
# include "./src/utils/philosophers_utils.h"

// Lists of log messages
# define LOG_FORK "has taken a fork\n"
# define LOG_EAT "is eating\n"
# define LOG_SLEEP "is sleeping\n"
# define LOG_THINK "is thinking\n"
# define LOG_DEAD "has taken a fork\n"

//Lists of errors
# define ERR_NUM "Capi wants only numbers as program args. Nothing else."
# define ERR_MINMAX "Capi wants only numbers between -2147483648 and 2147483647. Last time you do this!!"
# define ERR_ARGS "Capi wants between 4 and 5 args:\n"
"\t1) number_of_philosophers\n"
"\t2) time to die\n"
"\t3) time to eat\n"
"\t4) time to sleep\n"
"\t5) (optional) number of times each philosophers must eat\n"
# define ERR_MEM "Capi failed to allocate memory."
# define ERR_NBPHILO "Capi wants to invite at least one people for the dinner.\n"

// main functions
void	define_lr_fork(t_capi *capi);

// check values are right
int	check_values_are_right(char **argv);
int	check_all_is_digit(char **argv, int	y);

// capi initialization
t_capi	*init_capi(int argc, char **argv);
int   	create_philosophers_squad(t_capi *capi);
int	    create_forks(t_capi *capi);
int     create_capi_mutexes(t_capi *capi);

// sejour at chalet
void	*sejour_at_chalet(t_capi *capi);
void  snoring_time(t_capi *capi);
void  fondue_time(t_capi *capi);

#endif
