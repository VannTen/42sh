/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh_hashtable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:52:16 by heynard           #+#    #+#             */
/*   Updated: 2018/01/12 17:52:16 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_hash_table		*init_hash_table(void)
{
	t_hash_table	*new_table;
	size_t			i;

	if ((new_table = malloc(sizeof(t_hash_table))) == NULL)
		return (NULL);
	i = 0;
	while (i < MAX_BIN)
		new_table->hash_table[i++] = NULL;
	return (new_table);
}

int					add_hash_table(t_hash_table *htable,
									const char *bin_name,
									const char *bin_path)
{
	t_hash_data		*data;
	int				hash;

	if (htable && bin_name && bin_path)
	{
		hash = hash_42sh(bin_name);
		while (htable->hash_table[hash] != NULL &&
			ft_strcmp(htable->hash_table[hash]->name, bin_name))
			hash++;
		if (htable->hash_table[hash] != NULL &&
			!ft_strcmp(htable->hash_table[hash]->name, bin_name))
			htable->hash_table[hash]->hits += 1;
		else
		{
			if ((data = malloc(sizeof(t_hash_data))) == NULL)
				return (1);
			data->name = ft_strdup(bin_name);
			data->path = ft_strdup(bin_path);
			data->hits = 1;
			htable->hash_table[hash] = data;
		}
		return (0);
	}
	return (2);
}

int					free_hash_table(t_hash_table *htable)
{
	size_t			i;

	i = 0;
	while (i < MAX_BIN)
	{
		if (htable->hash_table[i] != NULL)
		{
			ft_strdel(&(htable->hash_table[i]->name));
			ft_strdel(&(htable->hash_table[i]->path));
			free(htable->hash_table[i]);
		}
		i++;
	}
	free(htable);
	htable = NULL;
	return (0);
}

char				*get_path_table(t_hash_table *htable,
									const char *bin_name)
{
	int				hash;

	if (htable && bin_name)
	{
		hash = hash_42sh(bin_name);
		while (htable->hash_table[hash] != NULL &&
			ft_strcmp(htable->hash_table[hash]->name, bin_name))
			hash++;
		if (htable->hash_table[hash] != NULL &&
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
