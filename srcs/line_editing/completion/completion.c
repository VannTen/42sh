/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:24:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/06 13:43:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

const char	*g_builtins_name[] = {
	"cd ",
	"declare ",
	"echo ",
	"env ",
	"exit ",
	"export ",
	"hash ",
	"history ",
	"setenv ",
	"unset ",
	"unsetenv ",
	NULL};

static int	eligible_to_env_completion(t_comp *comp)
{
	int	len;
	int	len_bis;

	len = ft_strlen(comp->prefix);
	len_bis = len;
	if (len)
		while ((ft_isalnum(comp->prefix[--len])
				|| comp->prefix[len] == '_') && len > -1)
			;
	if (comp->prefix[len] == '$')
	{
		ft_strdel(&comp->basename);
		if (!(comp->basename = ft_strdup(comp->prefix + len + 1)))
			return (MALLOC_FAIL);
		comp->basename_len = len_bis - len - 1;
		return (1);
	}
	return (0);
}

static int	add_builtin(t_comp *comp)
{
	t_list	*elem;
	int		i;

	i = -1;
	while (g_builtins_name[++i])
	{
		if (!ft_strncmp(g_builtins_name[i], comp->basename, comp->basename_len))
		{
			if (!(elem = ft_lstnew(g_builtins_name[i],
							ft_strlen(g_builtins_name[i]) + 1)))
				return (MALLOC_FAIL);
			elem->next = comp->matches;
			comp->matches = elem;
			comp->nb_matches++;
		}
	}
	return (0);
}

int			completion(t_input *input)
{
	int		ret;

	if (!input->comp.matches)
	{
		if ((ret = eligible_to_env_completion(&input->comp)) == MALLOC_FAIL)
			return (MALLOC_FAIL);
		else if (ret)
			input->comp.matches = completion_search_in_env(&input->comp);
		else if (input->comp.search_location == PATH)
		{
			if ((ret = completion_search_path(&input->comp)))
				return (ret);
		}
		else if (input->comp.search_location == DIRECTORY)
			if (!(input->comp.matches = open_and_read_directory(&input->comp,
									input->comp.dirname))
					&& input->comp.nb_matches < 0)
				return (MALLOC_FAIL);
		(input->comp.search_location == PATH) ? add_builtin(&input->comp) : 0;
	}
	input->comp.matches = merge_sort_matches(input->comp.matches);
	if (input->comp.matches)
		completion_display(&input->comp, input);
	return (0);
}
