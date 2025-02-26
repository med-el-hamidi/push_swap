#include "checker_bonus.h"

static void	_fill_stack(t_stack **a, char ***argv);
static void _checker(t_stack **a);
static int _check_format(char *buffer);
static int _check_order(t_stack **a, t_instruct *ins);

int main(int ac, char **av)
{
	t_stack	*a;
	char	***argv;

	if (ac < 2)
		return (EXIT_INVALID_INPUT);
	argv = handle_input(&ac, av);
	if (ac == 1)
		free_exit(EXIT_SUCCESS, argv);
	a = NULL;
	_fill_stack(&a, argv);
	handle_occurence(a);
	if (is_sorted(a))
		free_exit (EXIT_SUCCESS, NULL);
	_checker(&a);
	return (EXIT_SUCCESS);
}

static void	_fill_stack(t_stack **a, char ***argv)
{
	t_stack	*node;
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			node = ft_lstnew(atoi(argv[i][j++]));
			if (!node)
			{
				ft_lstclear(a);
				free_exit(EXIT_FAILURE, argv);
			}
			ft_lstadd_back(a, node);
		}
	}
	free_argv(argv);
}

static void	_checker(t_stack **a)
{
	t_instruct	*ins;
	t_instruct	*node;
	char		buffer[5];
	ssize_t		bytes;

	ins = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		ft_bzero(buffer, 5);
		bytes = read(1, buffer, 5);
		if (bytes == -1 || !_check_format(buffer))
		{
			ft_lstclear(a);
			ft_lstclear_(&ins);
			if (bytes == -1)
				free_exit (EXIT_FAILURE_READ, NULL);
			else
				free_exit (EXIT_WRONG_FORMAT, NULL);
		}
		if (buffer[0] == '\n')
			break ;
		node = ft_lstnew_(buffer);
		if (!node || (node && !node->str))
		{
			ft_lstclear(a);
			ft_lstclear_(&ins);
			free_exit (EXIT_FAILURE, NULL);
		}
		ft_lstadd_back_(&ins, node);
	}
	if (_check_order(a, ins))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(a);
	ft_lstclear_(&ins);
}

static int _check_format(char *buffer)
{
	if (!ft_strncmp(buffer, "pa\n", 4)
		|| !ft_strncmp(buffer, "pb\n", 4)
		|| !ft_strncmp(buffer, "sa\n", 4)
		|| !ft_strncmp(buffer, "sb\n", 4)
		|| !ft_strncmp(buffer, "ss\n", 4)
		|| !ft_strncmp(buffer, "ra\n", 4)
		|| !ft_strncmp(buffer, "rra\n", 5)
		|| !ft_strncmp(buffer, "rb\n", 4)
		|| !ft_strncmp(buffer, "rrb\n", 5)
		|| !ft_strncmp(buffer, "rr\n", 4)
		|| !ft_strncmp(buffer, "rrr\n", 5)
		|| buffer[0] == '\n')
		return (1);
	return (0);
}

static int _check_order(t_stack **a, t_instruct *ins)
{
	t_stack		*b;
	t_instruct	*ptr;

	b = NULL;
	ptr = ins;
	while (ptr)
	{
		if (!ft_strncmp(ptr->str, "pa\n", 4))
			push(a, &b);
		else if (!ft_strncmp(ptr->str, "pb\n", 4))
			push(&b, a);
		else if (!ft_strncmp(ptr->str, "sa\n", 4))
			swap(a);
		else if (!ft_strncmp(ptr->str, "sb\n", 4))
			swap(&b);
		else if (!ft_strncmp(ptr->str, "ss\n", 4))
			ss(a, &b);
		else if (!ft_strncmp(ptr->str, "ra\n", 4))
			rotate(a);
		else if (!ft_strncmp(ptr->str, "rb\n", 4))
			rotate(&b);
		else if (!ft_strncmp(ptr->str, "rra\n", 5))
			rrotate(a);
		else if (!ft_strncmp(ptr->str, "rrb\n", 5))
			rrotate(&b);
		else if (!ft_strncmp(ptr->str, "rr\n", 4))
			rr(a, &b);
		else if (!ft_strncmp(ptr->str, "rrr\n", 5))
			rrr(a, &b);
		ptr = ptr->next;
	}
	if (b)
	{
		ft_lstclear(&b);
		return (0);
	}
	return (is_sorted(*a));
}
