#ifndef PHILOSOPHERS_GENERAL_H
# define PHILOSOPHERS_GENERAL_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "./philosophers_struct.h"
# include "./src/utils/philosophers_utils.h"

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
void	define_lr_fork(t_data *data);

// check values are right
int	check_values_are_right(char **argv);
int	check_all_is_digit(char **argv, int	y);

// data initialization
t_data	*init_data(int argc, char **argv);
int   	create_philosophers_squad(t_data *data);
int	    create_forks(t_data *data);
int     create_data_mutexes(t_data *data);

// sejour at chalet
void	*sejour_at_chalet(t_data *data);
void  snoring_time(t_data *data);
void  fondue_time(t_data *data);

#endif
