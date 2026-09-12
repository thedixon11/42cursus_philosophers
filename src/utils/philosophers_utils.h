#ifndef PHILOSOPHERS_GENERAL_H
# define PHILOSOPHERS_GENERAL_H

//philo utils
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
