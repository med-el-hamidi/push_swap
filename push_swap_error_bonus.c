#include "checker_bonus.h"

void	free_argv(char ***argv)
{
	int	i;
	int	j;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			free(argv[i][j]);
			j++;
		}
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_exit(int e, char ***argv)
{
	if (argv)
		free_argv(argv);
	if (e > 0)
		ft_putstr_fd("Error\n", 2);
	exit (e);
}

void	freelsts_exit(int e, t_stack **a, t_instruct **ins)
{
	ft_lstclear(a);
	ft_lstclear_(ins);
	if (e > 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (e);
	}
}
