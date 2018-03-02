/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:07:10 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/02 10:09:38 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libbj.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (content == NULL || content_size == 0)
		return (NULL);
	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((new->content = (void*)malloc(content_size)) == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
