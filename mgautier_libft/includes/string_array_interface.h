/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_interface.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:59:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/23 11:37:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_INTERFACE_H
# define STRING_ARRAY_INTERFACE_H
# include <stdarg.h>
# include <stddef.h>
# include "bool_interface.h"

/*
** String array functions
** Implemenation files : name of the function
*/

void	ft_gen_free_string_array(void **string_array);
char	**ft_free_string_array(char ***tab);
void	free_only_str_array(char const ***tab);
char	**ft_str_array_cpy(char *const *src, char **dst);

/*
** Copying and transform by copy
** Implementation file : ft_string_array_dup.c
*/

char	**ft_string_array_dup(char const *const *string_array);
char	**ft_str_array_map_va(char const *const *str_array,
		char *(*map)(char const*, va_list), ...);
char	**ft_str_array_map_vas(char const *const *str_array,
		char *(*map)(char const*, va_list),
		va_list args);

/*
** Display functions
** Implentation file : ft_print_string_array.c
*/

void	ft_print_string_array(char const *const *str_array, char const *sep);
void	ft_print_string_array_fd(int fd,
		char const *const *str_array, char const *sep);

/*
** Getters
** Implementation file : string_array_get.c
*/

size_t	ft_string_array_count(char const *const *string_array);
int		ft_str_arraycmp(char const *const *array_1, char const *const *array_2);
t_bool	ft_str_arr_equ(char const *const *arr_1, char const *const *arr_2);

/*
** Update the array in various ways
** Implementation file : string_array_update.c
** ft_strip_invalid : strip an array of all strings on which (*is_valid) returns
** FALSE.
*/

void	ft_strip_invalid(char **array, t_bool (*is_valid)(const char *));

#endif
