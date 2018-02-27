/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_correctness.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:07:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/27 19:08:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote_defs.h"
#include "bool_interface.h"
#include "string_interface.h"

void	update_states(t_bool *states, char c,
		char const *quotes_char)
{
	size_t	index;
	size_t	states_index;

	index = 0;
	while (quotes_char[index] != c && quotes_char[index] != '\0')
		index++;
	if (quotes_char[index] != '\0')
	{
		states_index = 0;
		while (quotes_char[states_index] != '\0')
		{
			if (states[states_index] && states_index != index)
				return ;
			states_index++;
		}
		states[index] = !states[index];
	}
}

int		return_result(t_bool const *states, size_t size)
{
	int	result;

	result = 0;
	while (((size_t)result) < size && !(states[result]))
		result++;
	return (result);
}

int		state_of_quote(char const *str, char const *quote_chars)
{
	t_bool			*quote_states;
	size_t			index;
	int				result;
	size_t			size;

	size = ft_strlen(quote_chars);
	quote_states = create_bool_array(size, FALSE);
	if (quote_states == NULL)
		return (-1);
	index = 0;
	while (str[index] != '\0')
	{
		update_states(quote_states, str[index], quote_chars);
		index++;
	}
	result = return_result(quote_states, size);
	destroy_bool_array(&quote_states, size);
	return (result);
}
