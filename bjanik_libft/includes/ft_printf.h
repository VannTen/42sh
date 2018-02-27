/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:12:45 by bjanik            #+#    #+#             */
/*   Updated: 2017/05/18 17:02:39 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# define OCTAL "01234567"
# define HEXA_U "0123456789ABCDEF"
# define HEXA_L "0123456789abcdef"
# define MAX_FLAG 5

int					g_error;

typedef struct		s_ret
{
	int				flag;
	int				flag2;
	int				flag3;
	int				flag4;
	int				flag5;
	int				width;
	int				precision;
	int				lenght;
	int				spec;
}					t_ret;

typedef struct		s_len
{
	int				hashtag;
	int				plus;
	int				width;
	int				precision;
	int				space;
}					t_len;

typedef struct		s_arg
{
	char			flags[MAX_FLAG + 1];
	char			spec;
	int				width;
	int				precision;
	char			lenght[3];
	char			*arg;
	wchar_t			*w_arg;
	int				arg_len;
	int				neg;
	char			*start_format_part;
	char			*end_format_part;
	char			*end_format;
	char			*print_hashtag;
	char			*print_width;
	char			*print_precision;
	t_ret			ret;
	t_len			len;
	struct s_arg	*next;
}					t_arg;

int					ft_printf(const char *format, ...);
const char			*parse_flags(const char *format, t_arg *p);
const char			*parse_remain(const char *format, t_arg *p, va_list ap);
int					check_flags(t_arg *p, char c);
int					check_precision(t_arg *p, const char *ormat, va_list ap);
int					check_width(t_arg *p, const char *c, va_list ap);
int					check_specifier(t_arg *p, char c);
int					check_lenght(t_arg *p, const char *c);
int					error_wrong_flag(t_arg *p, char c);
int					error_wrong_lenght(t_arg *p);
int					error_ignored_flags(t_arg *p);
int					error_null_param(void);
int					invalid_conversion_specifier(char c);
int					incompatible_flag_and_specifier(t_arg *p, char c);
int					incompatible_lenght_and_specifier(t_arg *p);
int					incompatible_precision_and_specifier(t_arg *p);
int					valid_flags(t_arg *p);
int					valid_remain(t_arg *p);
char				*convert_decimal(t_arg *p, va_list ap);
char				*convert_long_decimal(t_arg *p, va_list ap);
char				*convert_hexa_upper(t_arg *p, va_list ap);
char				*convert_hexa_lower(t_arg *p, va_list ap);
char				*convert_octal(t_arg *p, va_list ap);
char				*convert_long_octal(t_arg *p, va_list ap);
char				*convert_unsigned(t_arg *p, va_list ap);
char				*convert_binary(t_arg *p, va_list ap);
char				*convert_unsigned_long(t_arg *p, va_list ap);
char				*convert_char(va_list ap);
wchar_t				*convert_wide_char(va_list ap);
int					is_flag(t_arg *p, char c);
const char			*multi_flags(const char *format, t_arg *p);
void				*handle_arg(t_arg *p, va_list ap);
int					handle_space(t_arg *p);
int					handle_plus(t_arg *p);
int					handle_hashtag(t_arg *p);
int					handle_width(t_arg *p);
int					handle_precision(t_arg *p);
int					handle_zeros(t_arg *p);
void				handle_wildcard(t_arg *p, va_list ap);
const char			*start_arg(t_arg *p, const char *format, va_list ap);
int					print_output(t_arg *p, const char *format);
t_arg				*create_elem(void);
void				init_arg(t_arg *arg);
void				init_ret(t_arg *arg);
void				append_list(t_arg **arg, t_arg **arg2);
void				free_arg_list(t_arg **p);
void				init_print(t_arg *arg);
int					print_wide_s(t_arg *p);
int					print_ls(t_arg *p);
int					print_wide_c(t_arg *p);
#endif
