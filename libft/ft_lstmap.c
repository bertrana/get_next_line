#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	if (!lst)
		return (NULL);
	begin = f(lst);
	tmp = begin;
	while (lst)
	{
		tmp = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (begin);
}
