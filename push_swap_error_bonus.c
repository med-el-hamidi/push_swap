#include "checker_bonus.h"

void	free_argv(char ***argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
	*argv = NULL;
}

void	free_exit(int e, char ***argv)
{
	if (argv)
		free_argv(argv);
	if (e > 0)
		ft_putstr_fd("Error\n", 2);
	exit (e);
}
