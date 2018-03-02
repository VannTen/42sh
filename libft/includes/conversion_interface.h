/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/03 12:09:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_INTERFACE_H
# define CONVERSION_INTERFACE_H
# include "bool_interface.h"
# include "variadic_args_interface.h"
# include <stdlib.h>

struct s_conversion;
typedef struct s_conversion	t_conversion;

/*
** Functions accessing the struc
*/

/*
** Ressource handling
** Implementation file : ft_conversion_private_ressources.c
*/

t_conversion	*conversion_ctor(void);
void			conversion_destroy(t_conversion *conversion);

/*
** Determine conversion type
** Implementation files :
** ft_conversion_private_is_conv_numeric.c
** ft_conversion_private_is_conv.c
*/

t_bool			is_signed_integer_conv(const t_conversion *conversion);
t_bool			is_unsigned_integer_conv(const t_conversion *conversion);
t_bool			is_integer_conv(const t_conversion *conversion);
t_bool			is_numeric(const t_conversion *conv);

t_bool			is_ptr_conv(const t_conversion *conversion);
t_bool			is_string_conv(const t_conversion *conversion);
t_bool			is_no_conv(const t_conversion *conversion);
t_bool			is_char_conv(const t_conversion *conv);

/*
** Set conversion parameters and make various adjustements on them
** Implementation file : ft_conversion_private_set_parameters.c
*/

void			set_conversion_spec_len(t_conversion *conv, int index);
void			settle_incompatibilities(t_conversion *conv);
void			post_parsing_conv(t_conversion *conv);
void			set_conversion_preceding_length(t_conversion *conv, int length);

/*
** Get conversion parameters
** Implementation file : ft_conversion_private_get_parameters.c
*/

size_t			get_modifier(const t_conversion *conversion);
int				ft_get_conv_len(const t_conversion *conv);
int				ft_get_conv_text_len(const t_conversion *conv);

/*
** Flags handlings
** Implementation file : ft_flags.c
*/

int				ft_write_flags(char *to_write, const t_conversion *conv);
int				ft_flags_len(const t_conversion *conv);
int				set_flags(const char *conversion_specifier,
		t_conversion *convers_specs);

/*
** Set conversion's final length
** Implementation file : ft_conversion_private_set_final_length.c
*/

typedef int	(*t_count)(const t_conversion *conv);
int				set_and_get_final_conversion_length(t_conversion *conv);
int				length_integers(t_conversion *conv, int conversion_result);
int				strings_chars_length(t_conversion *conv,
		t_count normal, t_count wide);

/*
** Get args index
** Implementation file : ft_conversion_private_args_index.c
*/

size_t			ft_arg_required(const void *conversion);
size_t			bigger_arg_required(const t_conversion *conv);
size_t			ft_precision_arg(const t_conversion *conv);
size_t			ft_field_width_arg(const t_conversion *conv);

/*
** Conversion validity (args, result)
** Implementation file : ft_conversion_private_is_valid.c
*/

t_bool			ft_conversion_arg_is_valid(const t_conversion *conv);
t_bool			ft_precision_arg_is_valid(const t_conversion *conv);
t_bool			ft_field_width_arg_is_valid(const t_conversion *conv);
t_bool			conversion_result_produces_error(const t_conversion *conv);

/*
** Set conversion variadic arguments
** Implementation file : ft_conversion_private_set_var_args.c
*/

void			ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array);
void			ft_normalize_args(t_conversion *conv);

/*
** Write conversion
** Implementation file : ft_conversion_private_write.c
*/

typedef int	(*t_specific_writer)(char *to_write, const t_conversion *conv);
int				ft_write_conversion(char *to_write, const t_conversion *conv);
int				ft_write_precision(char *to_write, const t_conversion *conv);
int				ft_write_field_width(char *to_write, int fill, char padding);
void			write_whole_conv(char *to_write, const t_conversion *conv,
		t_specific_writer specific_supp, t_specific_writer result_writer);
void			write_whole_conv_strings_chars(char *to_write,
		const t_conversion *conv, t_specific_writer result_writer);

/*
** Compute positions for write functions
** Implementation file : ft_conversion_private_positions_write.c
*/

char			*start_of_conv_is(const char *global_start,
		const t_conversion *conv);
char			*start_of_field_width_is(const char *global_start,
		const t_conversion *conv);

/*
** Functions selectors for len and write
** Implementation file : ft_conversion_private_function_selectors.c
*/

int				ft_get_len_conv(const t_conversion *conv);
void			ft_select_writer_conv(char *to_write, const t_conversion *conv);

/*
** Specifics for integer conversion (length)
** Implementation file : ft_conversion_private_integer_length.c
*/

void			handle_zero_padding(t_conversion *conv);
int				set_integer_length(t_conversion *conv);
int				count_alternate_form(const t_conversion *conv);

/*
** Specifis for integer conversion (write)
** Implementaton file : ft_conversion_private_integer_write.c
*/

int				ft_write_integer_conv(char *to_write, const t_conversion *conv);
t_bool			has_alternate_form_hexa(const t_conversion *conv);

#endif
