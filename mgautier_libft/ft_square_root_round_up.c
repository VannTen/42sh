/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_root_round_up.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:57:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/12 20:43:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_square_root_round_up(unsigned int square)
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
	return (square_root);
}
