#include "libft.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		(*lst)->index = 0;
		free(*lst);
		*lst = tmp;
	}
}
