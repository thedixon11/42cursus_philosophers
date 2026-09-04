#include "../philosophers_general.h"

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
