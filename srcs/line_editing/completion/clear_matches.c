/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_matches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:24:43 by bjanik            #+#    #+#             */
/*   Updated: 2018/03/06 11:17:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	*clear_matches_and_dir(t_comp *comp, t_list *matches, DIR *dirp)
{
	ft_lstdel(&matches, del_matches);
	comp->nb_matches = -1;
	if (dirp)
		closedir(dirp);
	return (NULL);
}
