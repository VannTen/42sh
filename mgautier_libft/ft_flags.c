/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:17:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/25 11:09:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags_defs.h"
#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "bool_interface.h"
#include <stdlib.h>

static t_bool	set_one_flag(const char *conversion_specifier, int index,
		t_conversion *convers_specs)
{
	enum e_flags		index_flags;
	static const char	flags[] = "#0- +'";

	index_flags = 0;
	while (index_flags < FLAGS_NBR
			&& conversion_specifier[index] != flags[index_flags])
		index_flags++;
	if (index_flags != FLAGS_NBR)
	{
		convers_specs->flags[index_flags] = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

int				set_flags(const char *conversion_specifier,
		t_conversion *convers_specs)
{
	int	index;

	index = 0;
	while (set_one_flag(conversion_specifier, index, convers_specs))
		index++;
	return (index);
}
