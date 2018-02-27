/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:23:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/21 15:02:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include <stdlib.h>

int	main(void)
{
	char const		*sym_names[] = {
		"HYU_7777",
		" HHY_IIII7   ",
		" HHH   JJJ_2",
		"JUIHIUH ",
		" HHHdddd",
		"dddd",
		" ",
		"\t\n " };
	t_bool const	validity[] = {
		TRUE, TRUE, FALSE, TRUE, FALSE, FALSE, FALSE, FALSE};
	size_t			index;

	index = 0;
	while (index < ARRAY_LENGTH(validity))
	{
		if (is_valid_sym_name(sym_names[index]) != validity[index])
			break ;
		index++;
	}
	return (index < ARRAY_LENGTH(validity) ? EXIT_FAILURE : EXIT_SUCCESS);
}
