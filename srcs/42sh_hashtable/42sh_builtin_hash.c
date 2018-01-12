/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_builtin_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:28:40 by heynard           #+#    #+#             */
/*   Updated: 2018/01/12 18:28:42 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

static void			print_current_table(t_hash_table *htable, int i)
{
	ft_dprintf(STDOUT_FILENO, "%-4d\t%s\n",
				htable->hash_table[i]->hits,
				htable->hash_table[i]->path);
}

int					builtin_hash(t_hash_table *htable)
{
	short int		check;
	int				i;

	if (htable)
	{
		i = 0;
		check = 0;
		while (i < MAX_BIN)
		{
			if (htable->hash_table[i] != NULL)
			{
				if (check == 0)
				{
					ft_putendl_fd("hits\tcommand", STDOUT_FILENO);
					check = 1;
				}
				print_current_table(htable, i);
			}
			i++;
		}
		if (!check)
			ft_putendl_fd("hash: hash table empty", STDOUT_FILENO);
		return (0);
	}
	return (1);
}
