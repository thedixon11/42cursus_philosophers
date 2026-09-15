/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:00:08 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 10:00:09 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers_utils.h"

void	*ph_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *) s;
	i = 0;
	while (i < n)
	{
		*ptr = (char) c;
		i++;
		ptr++;
	}
	return (s);
}
