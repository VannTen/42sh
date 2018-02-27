/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_interface.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:39:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/12 18:24:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_INTERFACE_H
# define STRING_INTERFACE_H
# include "lst_interface.h"
# include <stddef.h>
# include <stdarg.h>

/*
** strlen and variants
** Implementation file : <function name for each, mostly>
*/

size_t	ft_strlen(const char *str);
size_t	ft_strnlen(const char *str, size_t size);
size_t	ft_strlen_gen(const char *str, char end_of_line);
size_t	ft_strnlen_gen(const char *str, size_t size,
		char end_of_line);

/*
** Duplication
** Implementation file : ft_strdup.c
*/

char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, size_t	size);
char	*ft_strdup_to(const char *src, char end);
char	*ft_strndup_to(const char *src, size_t	size, char end);

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*
** Gen strdup
** Implementation file : ft_gen_strdup.c
*/

void	*ft_gen_strdup(const void *src);
/*
** Compare
** Implementation files : name of the function (except for ft_strequ_short,
** same as ft_strequ).
*/

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Equn
** Implementation file : ft_strnequ.c
*/

t_bool	ft_strnequ(char const *s1, char const *s2, size_t n);
t_bool	ft_gen_strnequ(void const *s1, va_list args);

/*
** Is equivalent
** Implementation file : ft_strequ.c
*/

t_bool	ft_strequ(char const *s1, char const *s2);
t_bool	ft_strequ_short(char const *s1, char const *s2);
t_bool	ft_gen_strequ(void const *s1, void const *s2);

/*
** Compare strings with other input sources
** Implementation file : string_cmp_to_other.c
*/

int		ft_str_fd_cmp(const char *str, int fd);

/*
** Search char in string
** Implementation files : name of the function
*/

char	*ft_strchr(const char *s, int c);
t_bool	string_has_char(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
char	last_char_of(const char *str);

/*
** Search string in string
** Implementation files : name of the function
*/

char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*
** Split strings
** Implementation files : name of the function
** ft_va_strstrip : provided as a convenience to be use with ft_strsplit_and,
** or other function that apply a variadic function on a set of strings. When
** used, the iterator function shall be given one (char const*) as its first
** variadic parameters.
*/

t_lst	*f_strsplit_lst(char const *str, char c);
t_lst	*f_strsplit_lst_mod(
		char const *str,
		char const *sep,
		t_bool merge_contiguous_sep);

char	**ft_strsplit(char const *s, char c);
char	**strsplit_with_str(char const *src, char const *seps);
char	**ft_strsplit_and(
		char const *str,
		char const c,
		char *(*map)(const char*, va_list),
		...);

/*
** Strip strings
** Implementation file : ft_strip.c
*/

char	*ft_strip(char const *src, char const *to_strip);
void	ft_strip_in_place(
		char *src,
		t_bool (*shall_remove)(char),
		t_bool keep);
char	*ft_va_strstrip(char const *str, va_list args);

/*
** Join strings
** Implementation files : name of the function
*/

char	*f_strljoin(char const *str_1, char const *str_2,
									size_t size_1, size_t size_2);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strvajoin(size_t nb_string, ...);
char	*ft_strjoin_ifnot(const char *src, const char *add);
t_bool	is_at_the_end(const char *src, const char *add);

/*
** Ressources management
** Implementation files : name of the function
*/

char	*ft_strnew_char(size_t size, char c);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_gen_strdel(void **str);
void	ft_strclr(char *s);

/*
** Iteration on elements, transformation
** Implementation files : name of the function
*/

void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s);

/*
** Substring functions
** Implementation file : ft_substring.c
*/

size_t	is_substring_up_to(const char *to_search, const char *to_be_searched);
size_t	is_initial_substring(const char *substring, const char *string);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Display strings
** Impelmentation file : name of the function
*/

void	ft_putstr(const char *s);
void	ft_putendl(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);

/*
** Relay of display string for higher order functions (used as functions
** pointers)
** Implementation file : string_put_gen.c
*/

void	ft_gen_putstr(void const *s);
void	ft_gen_putendl(void const *s);
void	ft_gen_putstr_fd(int fd, void const *s);
void	ft_gen_putendl_fd(int fd, void const *s);
void	ft_putstr_fd_sep_gen(void const *s, va_list args);

#endif
