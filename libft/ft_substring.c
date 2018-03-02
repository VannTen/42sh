/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:34:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/16 12:53:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

size_t	is_substring_up_to(const char *to_search, const char *to_be_searched)
{
	size_t	index;

	index = 0;
	while (to_search[index] == to_be_searched[index] && to_search[index] != '\0')
		index++;
	return (index);
}

size_t	is_initial_substring(const char *substring, const char *string)
{
	size_t	end_of_match;

	end_of_match = is_substring_up_to(substring, string);
	if (substring[end_of_match] != '\0')
		end_of_match = 0;
	return (end_of_match);
}
