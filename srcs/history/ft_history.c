/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:14:17 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/04 18:08:36 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsh.h"

static int		display_history(t_history *hist)
{
	t_dlst		*end;
	int			cpt;

	end = hist->end;
	cpt = 0;
	while (end)
	{
		ft_printf("%d  %s\n", ++cpt, (char*)end->data);
		end = end->prev;
	}
	return (0);
}

void			del_hist(void *data, size_t data_size)
{
	(void)data_size;
	ft_memdel(&data);
}

int				ft_history(t_env **env, char **cmd)
{
	t_history	*hist;
	char		options[5];
	char		wrong_opt;
	int			i;

	(void)env;
	hist = get_bsh()->history;
	i = 0;
	while (cmd[++i] && cmd[i][0] == '-' && ft_strcmp("--", cmd[i]))
	{
		if (!cmd[i][1])
		{
			ft_putendl_fd("bsh: history: `-': not a valid identifier", STDERR);
			return (1);
		}
		if ((wrong_opt = check_arg_opt(cmd[i] + 1, HISTORY_OPTIONS, options)))
			return (history_usage(wrong_opt, INVALID_OPT));
	}
	if (IS_OPTION(options, 'c'))
	{
		ft_dlstdel(&hist->head, del_hist);
		hist->end = NULL;
	}
	(i == 1) ? display_history(hist) : 0;
	return (0);
}
