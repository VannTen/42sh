/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbj.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:55:18 by bjanik            #+#    #+#             */
/*   Updated: 2018/02/27 11:04:11 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBJ_H
# define LIBBJ_H
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_list
{
	void		*content;
	size_t		content_size;
}				t_list;

int				ft_abs(int i);
int				ft_str_isdigit(char *str);
void			ft_free_string_tab(char ***tab);
void			ft_swap(void **a, void **b);
char			*ft_strnjoin(char *s1, int n, ...);
char			*ft_strndup(const char *s1, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
#endif
