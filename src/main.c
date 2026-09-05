#include "../philosophers_general.h"



int	check_values_are_right(char **argv)
{
	int	x;
	int	y;

	i = 0;
	y = 1;

	while (argv[y] != NULL)
	{
		while (argv[y][x] != NULL)
    {
      if (ph_isdigit(argv[y][x] != 1))
        return (1);
      x++;
    }
    y++;
	}
  return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if ((argc != 4) || (argc != 5))
		return (printf("Program need 4 or 5 args please\n"), 1);
  if (check_values_are_right(argv) == 1)
    return (printf("Please only numbers in args thx bro\n"), 1);
	data = init_data(argv);
}
