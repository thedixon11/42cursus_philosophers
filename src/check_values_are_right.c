#include "../philosophers_general.h"

int	check_all_is_digit(char **argv, int	y)
{
	int	x;

	x = 0;
	while (argv[y][x] != NULL)
	{
		if (ph_isdigit(argv[y][x] != 1))
			return (ph_putendl_fd(ERR_NUM, 2), 1);
		x++;
	}
	return (0);
}

int	check_values_are_right(char **argv)
{
	int	y;

	y = 1;
	while (argv[y] != NULL)
	{
		if (check_all_is_digit(argv, y) == 1)
			return (1);
		if ((ph_atol(argv[y][x]) < 0) || (ph_atol(argv[y][x]) > INT_MAX))
			return (ph_putendl_fd(ERR_MINMAX, 2), 1);
		y++;
	}
	if (ph_atol(argv[1]) > 1)
		return (ph_putendl_fd(ERR_NBPHILO, 2), 1);
	return (0);
}
