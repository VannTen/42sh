/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:00:00 by mgautier          #+#    #+#             */
/*   Updated: 2018/01/09 17:50:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_INTERFACE_H
# define FIFO_INTERFACE_H
# include "bool_interface.h"
# include "lst_interface.h"
# include "custom_stddef.h"
# include <stdarg.h>

typedef struct s_fifo	t_fifo;

/*
** Ressources management
** Implementation file : f_fifo_ressources.c
*/

t_fifo				*f_fifo_create(void);
t_lst				*f_fifo_extract(t_fifo **fifo);
void				f_fifo_destroy(t_fifo **fifo, t_destroy del);

/*
** Add and take elems
** Implementation file : f_fifo_add_take.c
*/

t_fifo				*f_fifo_add(t_fifo *fifo, const void *content);
void				*f_fifo_take(t_fifo *fifo);

/*
** Relay of list functions
** Implementation files : f_fifo_lstrelay.c && f_fifo_lstrelay.c
*/

void				f_fifoiter(t_fifo *fifo, void (*f)(void*));
void				f_fifoiterarray(void *array, t_fifo *fifo,
		void (*apply)(void *lst_content, void *array));
size_t				f_fifomax(t_fifo *fifo, size_t (*get_max)(const void*));
int					f_fifosum_content(t_fifo *fifo,
		int (*add)(const void*));
int					f_fifodosum(t_fifo *fifo, int (*add)(void*));
void const			*f_fifo_first_elem(const t_fifo *fifo);
size_t				f_fifoarray_end_early(void *array, t_fifo *fifo,
		size_t size, t_bool (*fifo_on_array)(const void *content, void *array));
void				f_fifomaparray(const void *src, void *dst, t_fifo *fifo,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier));

/*
** Valid every member
** Implementation file : f_fifo_every_valid.c
** (relay of t_lst functions)
*/

void				*f_fifo_every_valid(t_fifo const *fifo,
		t_bool (*test)(const void *content));
void				*f_fifo_every_valid_va(
		t_fifo const *fifo,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args),
		...);
void				*f_fifo_every_valid_vas(
		t_fifo const *fifo,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args),
		va_list args);

/*
** Take elem of fifo
** These function take out of the list elems that match the given function.
** Implementation file : fifo_take_elems.c
*/

void				*f_fifotakeone_if_vas(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
void				*f_fifotakeone_if_va(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);
t_fifo				*f_split_fifo_vas(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
t_fifo				*f_split_fifo_va(
		t_fifo *fifo,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);

/*
** Iteration
** Implementation files : f_fifo_iter.c & f_fifo_iter_variadic.c
*/

void				f_fifoiter_va(t_fifo const *fifo,
		void (*iter)(const void *elem, va_list),
		...);
void				f_fifoiter_vas(t_fifo const *fifo,
		void (*iter)(const void *elem, va_list),
		va_list args);
t_bool				f_fifoiterr_va(t_fifo *fifo,
		t_bool (*iter)(void *elem, va_list),
		...);
t_bool				f_fifoiterr_vas(t_fifo *fifo,
		t_bool (*iter)(void *elem, va_list),
		va_list args);
t_bool				f_fifoiterr(t_fifo *fifo, t_bool (*iter)(void *elem));

/*
** Getters : obtain information about object
** Implementation file : fifo_get.c
*/

size_t				fifo_len(t_fifo const *fifo);

/*
** Get ref to elems inside the list, without taking them.
** Implementation file : fifo_get_elems.c
*/

void const			*get_fifo_elem(t_fifo const *fifo, size_t index);

/*
** Acts on several fifo in various ways.
** Implementation file : fifo_several.c
*/

t_bool				fifo_are_equ(t_fifo const *fifo1, t_fifo const *fifo2,
		t_bool (*equ)(void const*, void const*))
		__attribute__((pure));
t_fifo				*join_fifo(t_fifo *fifo_1, t_fifo *fifo_2);
t_fifo				*add_lst_to_fifo(t_fifo *fifo, t_lst *lst);

/*
** Check equivalence of fifos.
** Implementation file : fifo_are_equivalent.c
*/

t_bool				fifo_same_contents(
		t_fifo const *fifo1,
		t_fifo const *fifo2,
		t_bool (*equ)(void const*, void const*));

/*
** Iterations with a functions that need the whole list as a reference
** parameters, to do stuff with it.
** Implementation file : lst_iter_on_itself.c
*/

t_bool				f_fifo_insert_on_itself_va(
		t_fifo *fifo,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		...);
t_bool				f_fifo_insert_on_itself_vas(
		t_fifo *fifo,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		va_list args);


/*
** Internal access
** Should mostly be used for debug, or when a t_lst is used which need another
** t_lst for comparison. Const to avoid internal corruption of the t_fifo object
** Implementation file : fifo_get_intern.c
*/

t_lst const			*get_intern_lst(t_fifo const *fifo);

#endif
