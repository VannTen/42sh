/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:01:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:32:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "issomething_interface.h"

#include "bool_interface.h"

t_bool		ft_isalnum(int c)
{
	return (ft_isalpha(c) + ft_isdigit(c));
}
