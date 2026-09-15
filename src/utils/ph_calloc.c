/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 09:59:57 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 09:59:59 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers_utils.h"

void	*ph_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;

	if (nmemb * size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == 0)
		return (NULL);
	ph_bzero(tab, nmemb * size);
	return (tab);
}
