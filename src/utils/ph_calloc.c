#include "../philosophers_general.h"

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
	ft_bzero(tab, nmemb * size);
	return (tab);
}
