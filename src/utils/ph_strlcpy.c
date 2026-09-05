#include "../philosophers_general.h"

size_t	ph_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizesrc;

	i = 0;
	sizesrc = ph_strlen(src);
	if (size == 0)
		return (sizesrc);
	while (src[i] != 0 && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (sizesrc);
}
