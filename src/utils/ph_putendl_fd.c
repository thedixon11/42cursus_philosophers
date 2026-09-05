#include "../philosophers_general.h"

void	ph_putendl_fd(char *s, int fd)
{
	size_t	i;
	char	*temp;

	if (!s)
		return ;
	i = ph_strlen(s);
	temp = ph_strjoin(s, "\n");
	write(fd, temp, i + 1);
	free(temp);
}
