/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:51:58 by heynard           #+#    #+#             */
/*   Updated: 2018/03/06 17:07:32 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# define MAX_UNIQUE 4096
# define COLLISION_TOLERANCE 3
# define MAX_BIN	MAX_UNIQUE * COLLISION_TOLERANCE

typedef struct		s_hash_table
{
	struct s_hash_data*	hash_table[MAX_BIN];
}					t_hash_table;

typedef struct		s_hash_data
{
	char	*name;
	char	*path;
	int		hits;
}					t_hash_data;

/*
** simple hash algorithm.
*/

int					hash_42sh(const char *bin_name);

/*
** function to set all hash table entries to NULL.
*/

void				init_hash_table(t_hash_table *hashtable);

/*
** function to allocate a new hash table entry.
*/

t_hash_data			*new_hash_data(const char *bin_name, const char *bin_path);

/*
** function to add a binary path inside the hash table using his name.
*/

int					add_hash_table(t_hash_table *htable,
									const char *bin_name,
									const char *bin_path);

/*
** function to free all the hash table structure and things inside.
*/

void				free_hash_table(t_hash_table *htable);

/*
** function returning path of a binary file if it exist in the hash table.
** warning : it doesn't allocate a copy of the path , only returning a pointer
** for verification.
*/

char				*get_path_table(t_hash_table *htable,
									const char *bin_name);

#endif
