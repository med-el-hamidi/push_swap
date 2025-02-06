#include "push_swap.h"

void	error_exit(int e)
{
	ft_printf("Error\n");
	exit (e);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_exit(int e, char **argv, int ac_changed)
{
	if (ac_changed)
		free_argv(argv);
	error_exit(e);
}
