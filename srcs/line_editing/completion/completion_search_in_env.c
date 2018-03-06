/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_search_in_env.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:27:33 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/06 13:02:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	*init_variables(t_env_list **env, char **str, t_comp *comp,
							int *ret)
{
	*env = get_shell_data()->env.env_list;
	*str = comp->basename;
	*ret = -1;
	return (NULL);
}

t_list		*completion_search_in_env(t_comp *comp)
{
	t_env_list	*env;
	t_list		*match[2];
	char		*str;
	int			ret;

	match[0] = init_variables(&env, &str, comp, &ret);
	while (env)
	{
		if (!(ret = ft_strncmp(str, env->name, ft_strlen(str))) && !match[0])
		{
			if (!(match[0] = ft_lstnew(env->name, ft_strlen(env->name) + 1)))
				return (clear_matches_and_dir(comp, match[0], NULL));
			match[1] = match[0];
		}
		else if (!ret)
		{
			if (!(match[1]->next = ft_lstnew(env->name,
							ft_strlen(env->name) + 1)))
				return (clear_matches_and_dir(comp, match[0], NULL));
			match[1] = match[1]->next;
		}
		env = env->next;
		(ret == 0) ? comp->nb_matches++ : 0;
	}
	return (match[0]);
}
