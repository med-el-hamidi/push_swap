#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int ))
{
	t_list	*ptr;

	if (!lst || !f)
		return ;
	ptr = lst;
	while (ptr != NULL)
	{
		f(ptr->nbr);
		ptr = ptr->next;
	}
}
