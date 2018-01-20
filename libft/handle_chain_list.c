/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chain_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:36:18 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/03 19:25:03 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*create_elem(void)
{
	t_arg *arg;

	if ((arg = (t_arg*)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	arg->next = NULL;
	init_arg(arg);
	return (arg);
}

void	append_list(t_arg **p, t_arg **p2)
{
	if (*p == NULL)
	{
		*p = create_elem();
		*p2 = *p;
	}
	else
	{
		(*p)->next = create_elem();
		*p = (*p)->next;
	}
	init_ret(*p);
}

void	free_arg_list(t_arg **p)
{
	t_arg	*list;

	list = *p;
	while (list)
	{
		list = list->next;
		if ((*p)->spec == 'S' || (*p)->spec == 's')
			(*p)->w_arg = NULL;
		if ((*p)->spec == 'C' || ((*p)->spec == 'c' && (*p)->lenght[0] == 'l'))
			ft_memdel((void**)&(*p)->w_arg);
		if ((*p)->spec != 's' || (((*p)->spec == 's' || (*p)->spec == 'S') &&
					(*p)->arg && !ft_strcmp((*p)->arg, "(null)")))
			ft_strdel(&(*p)->arg);
		ft_strdel(&((*p)->print_hashtag));
		ft_strdel(&(*p)->print_width);
		ft_strdel(&(*p)->print_precision);
		ft_memdel((void**)p);
		*p = list;
	}
}
