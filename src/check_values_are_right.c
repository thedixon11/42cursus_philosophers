#include "../philosophers_general.h"
#include "utils/philosophers_utils.h"

int	check_all_is_digit(char **argv, int y)
{
	int	x;

	x = 0;
	while (argv[y][x] != 0)
	{
		if (ph_isdigit(argv[y][x]) != 1)
			return (ph_putendl_fd(ERR_NUM, 2), 1);
		x++;
	}
	return (0);
}

int	check_values_are_right(int argc, char **argv)
{
	int	y;

	y = 1;
	while (argv[y] != NULL)
	{
		if (check_all_is_digit(argv, y) == 1)
			return (1);
		if ((ph_atol(argv[y]) < 0) || (ph_atol(argv[y]) > INT_MAX))
			return (ph_putendl_fd(ERR_MINMAX, 2), 1);
		y++;
	}
	if (ph_atol(argv[1]) < 1)
		return (ph_putendl_fd(ERR_NBPHILO, 2), 1);
	if (argc == 6 && ph_atol(argv[5]) == 0)
		return (ph_putendl_fd(ERR_FULL, 2), 1);
	return (0);
}
