#include "shell.h"

static t_list	*split_list(t_list *list)
{
	t_list	*second;
	t_list	*slow;
	t_list	*fast;

	fast = list;
	slow = list;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	second = slow->next;
	slow->next = NULL;
	return (second);
}

t_list			*merge_lists(t_list *first, t_list *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (ft_strcmp((char*)first->content, (char*)second->content) <= 0)
	{
		first->next = merge_lists(first->next, second);
		return (first);
	}
	else
	{
		second->next = merge_lists(first, second->next);
		return (second);
	}
}

t_list			*merge_sort_matches(t_list *first)
{
	t_list	*second;

	if (!first || !first->next)
		return (first);
	second = split_list(first);
	first = merge_sort_matches(first);
	second = merge_sort_matches(second);
	return (merge_lists(first, second));
}
