/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:01:17 by bjanik            #+#    #+#             */
/*   Updated: 2017/01/18 17:10:20 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quick_sort(int *tab, size_t start, size_t end)
{
	int	pivot;
	int	right;
	int	left;

	pivot = tab[(start + end) / 2];
	left = start - 1;
	right = end + 1;
	while (tab[left] < pivot)
		left++;
	while (tab[right] > pivot)
		right--;
}
