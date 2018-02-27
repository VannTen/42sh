/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_on_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:48:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/12 15:51:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool_defs.h"

t_bool	equal_char(char to_test, char to_test_against)
{
	return (to_test == to_test_against);
}

t_bool	diff_char(char to_test, char to_test_against)
{
	return (to_test != to_test_against);
}

t_bool	lower_char(char to_test, char to_test_against)
{
	return (to_test < to_test_against);
}

t_bool	greater_char(char to_test, char to_test_against)
{
	return (to_test > to_test_against);
}

t_bool	lower_equal_char(char to_test, char to_test_against)
{
	return (to_test <= to_test_against);
}
