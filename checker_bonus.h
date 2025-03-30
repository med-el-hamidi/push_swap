#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define EXIT_INVALID_INPUT 2
# define EXIT_NOT_INT 4
# define EXIT_OCCURENCE 11
# define EXIT_FAILURE_READ 5
# define EXIT_WRONG_FORMAT 7

typedef struct s_instruct
{
	char				*str;
	struct s_instruct	*next;
}	t_instruct;

void		free_argv(char ***argv);
void		free_exit(int e, char ***argv);
void		freelsts_exit(int e, t_stack **a, t_instruct **ins);

char		***handle_input(int *ac, char **av);
void		handle_occurence(t_stack *a);
int			is_sorted(t_stack *a);

int			swap(t_stack **stack);
int			push(t_stack **to, t_stack **from);
void		rotate(t_stack **stack);
void		rrotate(t_stack **stack);

void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

t_instruct	*ft_lstnew_(char *str);
void		ft_lstadd_back_(t_instruct **lst, t_instruct *new);
void		ft_lstclear_(t_instruct **lst);

void		output(t_stack **a, t_instruct *ins);
#endif
