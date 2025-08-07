
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (lst == NULL)
	{
		return ;
	}
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}