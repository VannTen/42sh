/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_errstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:27:52 by ble-berr          #+#    #+#             */
/*   Updated: 2018/03/05 11:24:05 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_sh_errstr_array.h"
#include "sh_error.h"

char const		*sh_errstr(int sh_errno)
{
	if (sh_errno < 0 || ELAST < sh_errno)
		sh_errno = 0;
	return (g_sh_errstr_array[sh_errno]);
}
