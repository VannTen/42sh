/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:07:58 by bjanik            #+#    #+#             */
/*   Updated: 2017/06/30 15:12:48 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(size)))
	{
		ft_putstr_fd("malloc failed", STDERR_FILENO);
		exit(-1);
	}
	return (ptr);
}
