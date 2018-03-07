/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:42:41 by heynard           #+#    #+#             */
/*   Updated: 2018/01/17 16:42:42 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static void			init_bracket(t_bracket *b, char *str)
{
	size_t			len;
	size_t			i;

	b->biglist = NULL;
	len = str ? ft_strlen(str) : 1;
	len++;
	if ((b->result = (char **)malloc(sizeof(char *) * len + 1)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return ;
	}
	i = 0;
	while (i <= len)
		b->result[i++] = NULL;
	b->current = 0;
	b->pos = 0;
	b->bs = 0;
	bracket_result_alloc(b, len);
}

static void			bracket_handle_quotes(char *str, size_t *i,
											t_bracket *b, char q)
{
	b->result[b->current][b->pos] = str[(*i)++];
	while (str[(*i)] != q && str[(*i)])
		b->result[b->current][b->pos] = str[(*i)++];
	b->result[b->current][b->pos] = str[(*i)++];
}

void			bracket_result_alloc(t_bracket *b, size_t len)
{
	if ((b->result[b->current] = (char *)malloc(sizeof(char) *
		len + 1)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		ft_free2dstr(b->result);
		b->result = NULL;
	}
	ft_bzero(b->result[b->current], len + 1);
}

char				**glob_bracket(char *str)
{
	int				correct;
	t_bracket		bracket;
	size_t			i;

	if (str == NULL)
		return (NULL);
	init_bracket(&bracket, str);
	if (bracket.result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		correct = 0;
		if (str[i] == '{' && bracket.bs == 0)
			correct = glob_parse_bracket(str, &i, &bracket);
		if (str[i] == '\\' && bracket.bs == 0)
			bracket.bs = 1;
		else if (str[i] == '"' || str[i] == '\'')
			bracket_handle_quotes(str, &i, &bracket, str[i]);
		else if (correct == 0)
		{
			bracket.bs = 0;
			bracket.result[bracket.current][bracket.pos] = str[i];
			bracket.pos++;
			if (str[i] != '\0')
				i++;
		}
	}
	if (bracket.biglist)
	{
		bracket.result = glob_bracket_bonding(&bracket);
		bracket.biglist = NULL;
	}
	return (bracket.result);
}
