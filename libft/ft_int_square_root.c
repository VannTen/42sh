/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_square_root.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:57:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/12 20:46:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_int_square_root(unsigned int square)
{
	int				odds;
	int				square_calc;
	unsigned int	square_root;

	odds = -1;
	square_root = 0;
	square_calc = (int)square;
	while (square_calc > 0)
	{
		odds = odds + 2;
		square_root++;
		square_calc = square_calc - odds;
	}
	if (square_calc != 0)
		square_root--;
	return (square_root);
}
