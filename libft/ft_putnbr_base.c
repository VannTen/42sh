/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 15:57:17 by bjanik            #+#    #+#             */
/*   Updated: 2017/04/10 16:52:09 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		single_char_in_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	if (single_char_in_base(base) == 0 || i == 1 || i == 0)
		return (0);
	else
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == '+' || base[i] == '-')
				return (0);
			i++;
		}
	}
	return (1);
}

void	my_putnbr(int nbr, char *base, int size_base)
{
	long nb;

	nb = nbr;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < size_base)
		ft_putchar(base[nb]);
	else
	{
		my_putnbr(nb / size_base, base, size_base);
		ft_putchar(base[nb % size_base]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size_base;

	size_base = 0;
	while (base[size_base])
		size_base++;
	if (check_base(base) == 0)
		return ;
	else
		my_putnbr(nbr, base, size_base);
}
