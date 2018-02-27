/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_set_test_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:02:51 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/21 16:02:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_bool	check_sets(void *set_cmp, void *item_array,
		size_t nb_item,
		t_bool (*check)(void const *cmp, void const *item))
{
	size_t	index;
	void	**cmp;
	void	**tested;

	index = 0;

	cmp = set_cmp;
	tested = item_array;
	while (index < nb_item)
	{
		if (!check(cmp[index], tested[index]))
			break ;
		index++;
	}
	return (index == nb_item);
}
