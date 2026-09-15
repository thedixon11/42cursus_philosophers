/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasconc <jvasconc@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 10:00:13 by jvasconc          #+#    #+#             */
/*   Updated: 2026/09/15 10:00:13 by jvasconc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers_utils.h"

char	*ph_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tab;
	size_t	sizes1;

	sizes1 = ph_strlen(s1) + 1;
	len = sizes1 + ph_strlen(s2);
	tab = ph_calloc(len, sizeof(char));
	if (!tab)
		return (0);
	ph_strlcpy(tab, s1, sizes1);
	ph_strlcat(tab, s2, len);
	return (tab);
}
