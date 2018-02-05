/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:24:25 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/03 17:05:44 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				completion(t_input *input)
{
	if (!input->comp.matches)
	{
		if (input->comp.prefix[0] == '$')
			input->comp.matches = completion_search_in_env(&input->comp);
		else if (input->comp.search_location == PATH)
			completion_search_path(&input->comp);
		else if (input->comp.search_location == DIRECTORY)
			input->comp.matches = open_and_read_directory(&input->comp,
									input->comp.dirname);
	}
	if (input->comp.matches)
		completion_display(&input->comp, input);
	return (0);
}
