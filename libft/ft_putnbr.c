/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:09:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 16:27:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdout_interface.h"
#include <unistd.h>

/*
** The recursion works that way : if n has more than one digit (n <= 10),
** write all digits before the last (with the recursive call);
** then write last digit.(n % 10)
*/

void		ft_putnbr(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
}
