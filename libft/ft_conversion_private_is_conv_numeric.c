/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_is_conv_numeric.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 11:03:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/21 12:17:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool_interface.h"

t_bool	is_signed_integer_conv(const t_conversion *conversion)
{
	return (conversion->type <= I);
}

t_bool	is_unsigned_integer_conv(const t_conversion *conversion)
{
	return ((conversion->type <= X_MAJ && conversion->type >= O) ||
			conversion->type == P);
}

t_bool	is_integer_conv(const t_conversion *conversion)
{
	return (is_signed_integer_conv(conversion)
			|| is_unsigned_integer_conv(conversion));
}

t_bool	is_numeric(const t_conversion *conv)
{
	return ((conv->type >= D && conv->type <= A_MAJ) ||
			conv->type == P);
}
