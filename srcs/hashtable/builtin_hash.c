/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_builtin_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:28:40 by heynard           #+#    #+#             */
/*   Updated: 2018/02/28 15:29:20 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "builtins.h"
#include "hashtable.h"
#include "libft.h"
#include <unistd.h>

static short int	print_hashed_commands(t_hash_table *htable)
{
	short int		cmd_found;
	int				i;

	i = 0;
	cmd_found = 0;
	while (i < MAX_BIN)
	{
		if (htable->hash_table[i] != NULL)
		{
			if (cmd_found == 0)
			{
				ft_putendl_fd("hits\tcommand", STDOUT_FILENO);
				cmd_found = 1;
			}
			ft_dprintf(STDOUT_FILENO, "%4d\t%s\n",
					htable->hash_table[i]->hits,
					htable->hash_table[i]->path);
		}
		i++;
	}
	return (cmd_found);
}

int					builtin_hash(char **argv, t_env *env)
{
	t_bsh			*const bsh = get_shell_data();
	t_hash_table	*htable;

	(void)argv;
	(void)env;
	if (bsh && (htable = &bsh->hashtable))
	{
		if (!print_hashed_commands(htable))
			ft_putendl_fd("hash: hash table empty", STDOUT_FILENO);
		return (0);
	}
	return (1);
}
