#include "libft.h"

t_list	*ft_lstmap(t_list *lst)
{
	t_list	*ptr;
	t_list	*new;
	t_list	*node;

	if (!lst)
		return (NULL);
	ptr = lst;
	new = NULL;
	while (ptr != NULL)
	{
		node = ft_lstnew(ptr->nbr);
		if (!node)
		{
			ft_lstclear(&new);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		ptr = ptr->next;
	}
	return (new);
}
