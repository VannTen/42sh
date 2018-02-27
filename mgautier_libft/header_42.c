/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_42.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:13:59 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 12:23:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "meta_programming_defs.h"
#include "string_interface.h"
#include "printf.h"
#include "useful_macros.h"
#include <stdlib.h>

void		print_header_42(int const fd, char const *file_name)
{
	char		*mail;
	const char	*date = "2017/10/13 15:56:34";
	const char	stars[] = REP(0, 7, 4, "*");

	mail = ft_strvajoin(3, "<", getenv("MAIL42"), ">");
	ft_dprintf(fd,
			"%1$s %2$s %3$s\n"
			"%1$-77s %3$s\n"
			"%1$-57s %4$-8.3s %4$-10s %3$s\n"
			"%1$-4s %5$-50s %6$-8s %6$-6s %6$-5s %3$s\n"
			"%1$-53s %7$s %7$-11s %7$-7s %3$s\n"
			"%1$-4s By: %8$s %9$-33s %10$-4s %7$-9s %10$-10s %3$s\n"
			"%1$-49s %10$s%11$s%10$s%11$-4.2s %10$-13s %3$s\n"
			"%1$-4s Created: %12$s by %8$-17s %11$-6s %11$-15s %3$s\n"
			"%1$-4s Updated: %12$s by %8$-16s %13$-5.3s %13$-17s %3$s\n"
			"%1$-77s %3$s\n"
			"%1$s %2$s %3$s\n", "/*", stars, "*/", "::::::::", file_name,
			":+:", "+:+", getenv("LOGNAME"), mail, "+#+", "#+#", date,
			"########.fr");
	ft_strdel(&mail);
}
