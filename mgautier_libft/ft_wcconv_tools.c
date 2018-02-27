/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcconv_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 10:41:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:23:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	generate_first_mask(unsigned int size)
{
	const unsigned int	ascii_mask = 0x7F;
	unsigned int		mask;
	unsigned int		count;

	mask = 037;
	count = 2;
	if (size == 1)
		mask = ascii_mask;
	while (count < size)
	{
		mask = mask >> 1;
		count++;
	}
	return (mask);
}

unsigned int	generate_utf_8_indic(unsigned int size)
{
	const unsigned int	ascii_indic = 0;
	unsigned int		indic;
	unsigned int		count;

	indic = 0300;
	count = 2;
	if (size == 1)
		indic = ascii_indic;
	while (count < size)
	{
		indic = (indic >> 1) | 128;
		count++;
	}
	return (indic);
}
