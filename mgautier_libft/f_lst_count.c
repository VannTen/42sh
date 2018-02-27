/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:33:27 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 16:10:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"

unsigned int	f_lst_len(const t_lst *lst)
{
	unsigned int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

unsigned int	f_lst_len_until(const t_lst *lst, void const *content)
{
	unsigned int	len;

	len = 0;
	while (lst != NULL && lst->content != content)
	{
		lst = lst->next;
		len++;
	}
	return (len + (lst != NULL ? 1 : 0));
}

int				f_lstsum_content(t_lst *list, int (*f)(const void *))
{
	int	sum;
	int	result;

	sum = 0;
	while (list != NULL)
	{
		result = f(list->content);
		if (result < 0)
			break ;
		sum += result;
		list = list->next;
	}
	return (sum);
}

int				f_lstdosum(t_lst *list, int (*f)(void *))
{
	int	sum;
	int	result;

	sum = 0;
	while (list != NULL)
	{
		result = f(list->content);
		if (result < 0)
			break ;
		sum += result;
		list = list->next;
	}
	return (sum);
}

size_t			f_lstmax(t_lst *list, size_t (*get_max)(const void *content))
{
	size_t	max;
	size_t	result;

	max = 0;
	while (list != NULL)
	{
		result = get_max(list->content);
		max = result > max ? result : max;
		list = list->next;
	}
	return (max);
}
