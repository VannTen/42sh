/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2Dstrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heynard <heynard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 17:47:24 by heynard           #+#    #+#             */
/*   Updated: 2018/01/24 17:48:02 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_glob.h"

static char				**ft_2dstrjoin_loop(char **t1, char **t2, char **final)
{
	int					i;
	int					j;

	i = t1 ? -1 : 0;
	if (t1)
	{
		while (t1[++i])
			final[i] = ft_strdup(t1[i]);
	}
	j = t2 ? -1 : 0;
	if (t2)
	{
		while (t2[++j])
			final[i + j] = ft_strdup(t2[j]);
	}
	final[i + j] = NULL;
	return (final);
}

char					**ft_2dstrjoin(char **t1, char **t2)
{
	char				**final;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (t1)
	{
		while (t1[i])
			i++;
	}
	if (t2)
	{
		while (t2[j])
			j++;
	}
	if ((final = (char **)malloc(sizeof(char *) * (i + j) + 1)) == NULL)
	{
		ft_putendl_fd("42sh: memory allocation failed", STDERR_FILENO);
		return (t1);
	}
	final = ft_2dstrjoin_loop(t1, t2, final);
	t1 ? ft_free2dstr(t1) : (0);
	t2 ? ft_free2dstr(t2) : (0);
	return (final);
}
