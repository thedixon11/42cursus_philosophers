#include "../philosophers_general.h"

long	ph_atol(const char *nptr)
{
	long	nb;
	int		neg;

	neg = 0;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		neg++;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + *nptr - 48;
		nptr++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
