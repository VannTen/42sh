/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:52:16 by heynard           #+#    #+#             */
/*   Updated: 2018/03/02 12:24:11 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"
#include <unistd.h>

void				init_hash_table(t_hash_table *hashtable)
{
	size_t			i;

	if (hashtable)
	{
		i = 0;
		while (i < MAX_BIN)
			hashtable->hash_table[i++] = NULL;
	}
}

int					add_hash_table(t_hash_table *htable,
									const char *bin_name,
									const char *bin_path)
{
	int				hash;

	if (htable && bin_name && bin_path)
	{
		hash = hash_42sh(bin_name);
		while (hash < MAX_BIN && htable->hash_table[hash] != NULL &&
			ft_strcmp(htable->hash_table[hash]->name, bin_name))
			hash++;
		if (hash < MAX_BIN && htable->hash_table[hash] != NULL &&
			!ft_strcmp(htable->hash_table[hash]->name, bin_name))
			htable->hash_table[hash]->hits += 1;
		else if (hash < MAX_BIN)
		{
			if (!(htable->hash_table[hash] = new_hash_data(bin_name, bin_path)))
				ft_dprintf(STDERR_FILENO, "42sh: %s: Failed to create hashtable"
						" entry, insufficient memory.\n", bin_name);
		}
		else
			ft_dprintf(STDERR_FILENO, "42sh: %s: hash table is full.\n",
					bin_name);
		return (0);
	}
	return (2);
}

void				free_hash_table(t_hash_table *htable)
{
	size_t			i;

	i = 0;
	while (i < MAX_BIN)
	{
		if (htable->hash_table[i] != NULL)
		{
			ft_strdel(&(htable->hash_table[i]->name));
			ft_strdel(&(htable->hash_table[i]->path));
			ft_memdel((void**)&(htable->hash_table[i]));
		}
		i++;
	}
}

char				*get_path_table(t_hash_table *htable,
									const char *bin_name)
{
	int				hash;

	if (htable && bin_name)
	{
		hash = hash_42sh(bin_name);
		while (hash < MAX_BIN && htable->hash_table[hash] != NULL &&
			ft_strcmp(htable->hash_table[hash]->name, bin_name))
			hash++;
		if (hash < MAX_BIN && htable->hash_table[hash] != NULL &&
			!ft_strcmp(htable->hash_table[hash]->name, bin_name))
			return (htable->hash_table[hash]->path);
	}
	return (NULL);
}

int					hash_42sh(const char *bin_name)
{
	int				hash;
	int				i;

	hash = 0;
	i = 0;
	while (bin_name[i])
		hash += (int)bin_name[i++];
	return (hash % MAX_BIN);
}
