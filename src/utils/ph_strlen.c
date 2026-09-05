#include "../philosophers_general.h"

size_t	ph_strlen(const char *s)
{
	size_t	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != 0)
		size++;
	return (size);
}
