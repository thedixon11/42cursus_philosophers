/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:59:18 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 09:59:20 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_UTILS_H
# define PHILOSOPHERS_UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>
# include <sys/time.h>

void	*ph_calloc(size_t nmemb, size_t size);
long	ph_atol(const char *nptr);
int		ph_atoi(const char *nptr);
void	ph_putendl_fd(char *s, int fd);
char	*ph_itoa(int n);
char	*ph_strjoin(char const *s1, char const *s2);
size_t	ph_strlcat(char *dst, const char *src, size_t size);
size_t	ph_strlcpy(char *dst, const char *src, size_t size);
void	ph_free(void **ptr);
size_t	ph_strlen(const char *s);
void	ph_bzero(void *s, size_t n);
int		ph_isdigit(int c);
void	*ph_memset(void *s, int c, size_t n);
void	ph_putendl_fd(char *s, int fd);

#endif
