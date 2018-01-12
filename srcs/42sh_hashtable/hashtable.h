/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:51:58 by heynard           #+#    #+#             */
/*   Updated: 2018/01/12 17:51:58 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# define MAX_BIN	4096;

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

int					hash_42sh(char *bin_name);

/*
** function to call to execute a simple builtin "hash", print on stdout
** all the binary that have been called by the current shell session and
** how many times.
*/

int					builtin_hash(t_hash_table *htable);

/*
** function to allocate hash table structure and his components.
*/

t_hash_table		*init_hash_table(void);

/*
** function to add a binary path inside the hash table using his name.
*/

int					add_hash_table(t_hash_table *htable,
									const char *bin_name,
									const char *bin_path);

/*
** function to free all the hash table structure and things inside.
*/

int					free_hash_table(t_hash_table *htable);

/*
** function returning path of a binary file if it exist in the hash table.
** warning : it doesn't allocate a copy of the path , only returning a pointer
** for verification.
*/

char				*get_path_table(t_hash_table *htable,
									const char *bin_name);


#endif
