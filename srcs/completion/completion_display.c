/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:37:48 by bjanik            #+#    #+#             */
/*   Updated: 2018/01/31 17:14:14 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	completion_display(t_comp comp, t_input *input)
{
	char	*str;
	char	*copy;

	str = (char*)comp.matches->content;
	copy = NULL;
	if (comp.nb_matches == 1)
	{
		if (comp.prefix[0] == '$')
			copy = ft_strdup(str + ft_strlen(comp.prefix + 1));
		else
			copy = ft_strdup(str + comp.basename_len);
		paste_str_in_buffer(copy, input);
	}
	else if (comp.nb_matches)
	{
	}
	ft_strdel(&copy);
	return (0);
}
