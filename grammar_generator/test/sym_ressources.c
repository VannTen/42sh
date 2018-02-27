/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_ressources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:46:53 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/06 14:51:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sym_interface.h"
#include <stdlib.h>

int	main(void)
{
	t_symbol	*sym;
	t_bool		result;

	sym = create_symbol("SYM");
	result = ft_strequ(get_name(sym), "SYM");
	destroy_symbol(&sym);
	result = result && (sym == NULL);
	return (result ? EXIT_SUCCESS : EXIT_FAILURE);
}
