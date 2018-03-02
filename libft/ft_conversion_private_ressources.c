/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_ressources.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:01:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:14:56 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "bool_interface.h"
#include <stdlib.h>

static void		init_flags(t_bool *flags)
{
	enum e_flags	index;

	index = 0;
	while (index < FLAGS_NBR)
	{
		flags[index] = FALSE;
		index++;
	}
}

static void		init_values(t_conversion *conversion)
{
	init_flags(conversion->flags);
	conversion->arg_index = 0;
	conversion->positional = FALSE;
	conversion->is_valid = TRUE;
	conversion->field_width.param.value = 0;
	conversion->precision.param.value = NO_PRECISION;
	conversion->field_width.is_arg = FALSE;
	conversion->precision.is_arg = FALSE;
	conversion->length_modifier = 0;
	conversion->result_length = 0;
	conversion->supp_length = 0;
	conversion->specifier_length = 0;
	conversion->preceding_length = 0;
	conversion->arg = NULL;
}

void			conversion_destroy(t_conversion *conversion)
{
	if (conversion != NULL)
		init_values(conversion);
	free(conversion);
}

t_conversion	*conversion_ctor(void)
{
	t_conversion	*conversion;

	conversion = malloc(sizeof(t_conversion));
	if (conversion != NULL)
		init_values(conversion);
	return (conversion);
}
