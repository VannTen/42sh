/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 11:35:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/19 11:41:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_interface.h"
#include "string_interface.h"
#include <unistd.h>
#include <stdlib.h>

void	fatal(void)
{
	ft_putstr_fd("FATAL ERROR... or something like that.\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
