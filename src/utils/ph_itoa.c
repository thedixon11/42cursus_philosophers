#include "../philosophers_general.h" 

static size_t	sizetocalloc(long int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ph_itoa(int n)
{
	size_t		size;
	char		*tab;
	long int	nbr;
	size_t		j;

	j = 0;
	nbr = n;
	size = sizetocalloc(nbr);
	tab = ph_calloc(size + 1, sizeof(char));
	if (!tab)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		tab[0] = '-';
		j = 1;
	}
	while (size > j)
	{
		tab[size - 1] = (nbr % 10) + 48;
		nbr /= 10;
		size--;
	}
	return (tab);
}
