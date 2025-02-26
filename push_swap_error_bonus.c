#include "checker_bonus.h"

void	free_argv(char ***argv)
{
	int	i;
	int	j;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			free(argv[i][j++]);
		free(argv[i++]);
	}
	free(argv);
}

void	free_exit(int e, char ***argv)
{
	free_argv(argv);
	if (e > 0)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("OK\n");
	exit (e);
}
