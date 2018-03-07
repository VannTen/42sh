/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_bracket_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:59:23 by heynard           #+#    #+#             */
/*   Updated: 2018/01/26 13:59:24 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static t_biglist		*create_blist_loop(int j, char **recursive,
											t_biglist *newbig)
{
	t_blist				*new;
	char				**newstr;

	if ((new = malloc(sizeof(t_blist))) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (newbig);
	}
	if ((newstr = (char **)malloc(sizeof(char *) * 2)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (newbig);
	}
	newstr[0] = ft_strdup(recursive[j]);
	newstr[1] = NULL;
	new->r_bracket = newstr;
	new->next = NULL;
	newbig->blist = add_blist(newbig, new);
	return (newbig);
}

t_biglist				*create_blist_recursive(char *str,
												int i,
												t_biglist *newbig,
												char limit)
{
	char				**recursive;
	char				*tmp;
	int					j;

	tmp = glob_strcpy_spec(&(str[i]), limit);
	recursive = glob_bracket(tmp);
	ft_strdel(&tmp);
	if (recursive == NULL || recursive[0] == NULL)
		return (newbig);
	j = 0;
	while (recursive[j] != NULL)
	{
		create_blist_loop(j, recursive, newbig);
		j++;
	}
	ft_free2dstr(recursive);
	return (newbig);
}

char					**glob_bracket_bonding(t_bracket *b)
{
	size_t				len;
	char				**final;

	if (!b->biglist)
		return (b->result);
	len = count_biglist(b->biglist);
	if ((final = (char **)malloc(sizeof(char *) * len + 1)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (b->result);
	}
	final[len] = NULL;
	final = fill_final(final, 0, b->result, b->biglist);
	ft_free2dstr(b->result);
	b->result = NULL;
	free_biglist(b->biglist);
	b->biglist = NULL;
	return (final);
}
