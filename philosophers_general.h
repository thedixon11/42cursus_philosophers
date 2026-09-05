#ifndef PHILOSOPHERS_GENERAL_H
# define PHILOSOPHERS_GENERAL_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "./philosophers_struct.h"

//Lists of errors
# define ERR_NUM "Capi wants only numbers as program args. Nothing else."
# define ERR_MINMAX "Capi wants only numbers between -2147483648 and 2147483647. Last time you do this."
# define ERR_ARGS "Capi wants between 4 and 5 args:\n"
"\t1) number_of_philosophers\n"
"\t2) time to die\n"
"\t3) time to eat\n"
"\t4) time to sleep\n"
"\t5) (optional) number of times each philosophers must eat\n"
# define ERR_MEM "Capi failed to allocate memory."

// main functions
void	dinner_is_over(t_data *data);

//utils
void	*ph_calloc(size_t nmemb, size_t size);
long	ph_atol(const char *nptr);
void	ph_putendl_fd(char *s, int fd);
char	*ph_itoa(int n);
char	*ph_strjoin(char const *s1, char const *s2);
size_t	ph_strlcat(char *dst, const char *src, size_t size);
size_t	ph_strlcpy(char *dst, const char *src, size_t size);
void	ph_free(void **ptr);
size_t	ph_strlen(const char *s);
void	ph_bzero(void *s, size_t n);
int	ph_isdigit(int c);
void	*ph_memset(void *s, int c, size_t n);

#endif
