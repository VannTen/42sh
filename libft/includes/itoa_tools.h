/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:15:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:14:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_TOOLS_H
# define ITOA_TOOLS_H
# include "bool_interface.h"
# include <stddef.h>
# include <stdint.h>
# define DECIMAL_DIGITS "0123456789"
# define OCTAL_DIGITS "01234567"
# define BINARY_DIGITS "01"
# define HEXADECIMAL_DIGITS "0123456789abcdef"
# define HEXADECIMAL_DIGITS_CAPS "0123456789ABCDEF"
# define DECIMAL_BASE sizeof(DECIMAL_DIGITS) - 1
# define OCTAL_BASE sizeof(OCTAL_DIGITS) - 1
# define BINARY_BASE sizeof(BINARY_DIGITS) - 1
# define HEXADECIMAL_BASE sizeof(HEXADECIMAL_DIGITS) - 1
# define HEXA_ALTERNATE_FORM "0x"
# define HEXA_MAJ_ALTERNATE_FORM "0X"
# define OCTAL_ALTERNATE_FORM "0"

size_t	itoa_len_signed(intmax_t number, int base);
size_t	itoa_len_unsigned(uintmax_t number, unsigned int base);
void	itoa_write_signed(char *str, intmax_t number, unsigned int base,
		const char *base_digits);
void	itoa_write_unsigned(char *str, uintmax_t number, unsigned int base,
		const char *base_digits);

#endif
