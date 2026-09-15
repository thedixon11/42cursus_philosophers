/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:00:11 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 10:00:11 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers_utils.h"

void	ph_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	*temp;

	if (!s)
		return ;
	i = ph_strlen(s);
	temp = ph_strjoin(s, "\n");
	write(fd, temp, i + 1);
	free(temp);
}
