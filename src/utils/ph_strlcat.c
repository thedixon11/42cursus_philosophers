#include "../philosophers_general.h"

size_t	ph_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sizesrc;
	size_t	sizedst;

	sizesrc = ph_strlen(src);
	sizedst = ph_strlen(dst);
	i = sizedst;
	j = 0;
	if (size <= sizedst)
		return (sizesrc + size);
	while ((src[j] != 0) && (i < (size - 1)))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
	return (sizesrc + sizedst);
}
