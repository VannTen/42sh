/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_interface.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:29:22 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/04 11:55:43 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_INTERFACE_H
# define LST_INTERFACE_H
# include "custom_stddef.h"
# include "bool_interface.h"
# include <stddef.h>
# include <stdarg.h>

typedef struct s_lst	t_lst;

/*
** Ressources management
** Implementation file : f_lst_ressources.c
*/

t_lst				*f_lstnew(void const *content);
void				f_lstdelone(t_lst *alst, t_destroy del);
void				f_lstdel(t_lst **alst, t_destroy del);
void				f_lstdel_set(
		t_lst **lst,
		void (*set_del)(void **set, void (*)(void**)),
		void (*del)(void**));

/*
** Elems insertion and removal
** Implementation : f_lst_insert_remove.c
*/

t_lst				*f_add_end_lst(t_lst *last_link, const void *content);
t_lst				*f_add_end_lst_2(t_lst **last_link, const void *content);
t_lst				*f_lstpush(void const *content, t_lst **list);
void				*f_lstpop(t_lst **list);
t_bool				f_lstremoveif_one(t_lst **lst, int ref,
		int (*match)(const void *elem), t_destroy del);

/*
** Operations on several lists
** Implementation file : lst_several.c
*/

t_lst				*join_lst(t_lst *lst_1, t_lst const *to_join);
t_lst				*lst_join(t_lst const *lst_1, t_lst const *to_join);
t_bool				lst_equ(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const*, void const*));
t_bool				lst_equ_to_n(t_lst const *lst1, t_lst const *lst2,
		size_t index,
		t_bool (*equ)(void const*, void const*));

/*
** Test list equivalence order-independently
** Implementation file : lst_are_equivalent.c
**
** lst_same_contents : content1 is the content of lst1, content2 is the content
** of lst2.
*/

t_bool				lst_same_contents(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const *content1, void const *content2));

/*
** Insert or delete on tail of the list
** Implementation file : f_lst_insert_remove_end.c
*/

void				*f_pushend_lst(t_lst **lst, void *content);
void				*f_popend_lst(t_lst	**lst);

/*
** Variadic function on list
** Those are intend to be used with function that take a void * + an arbitrary
** number of arguments, but there is no check if the argument list is correct.
** Implementation file : f_lst_variadic.c
*/

void				f_lstremoveif_va(t_lst **lst,
		t_bool (*match)(const void *elem, va_list),
		t_destroy content_dtor, ...);
void				f_lstiter_va(t_lst const *lst,
		void (*iter)(const void *elem, va_list),
		...);
void				f_lstiter_vas(t_lst const *lst,
		void (*iter)(const void *elem, va_list),
		va_list args);
void				f_lstiteri_va(t_lst const *lst,
		void (*iter)(const void *elem, size_t index, va_list),
		...);
void				f_lstiteri_vas(t_lst const *lst,
		void (*iter)(const void *elem, size_t index, va_list),
		va_list args);

/*
** Take elem of list
** These function take out of the list elems that match the given function.
** Implementation file : lst_take_elems.c
*/

void				*f_lsttakeone_if_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
void				*f_lsttakeone_if_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);
t_lst				*f_split_lst_vas(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		va_list args);
t_lst				*f_split_lst_va(
		t_lst **lst,
		t_bool truth,
		t_bool (*match)(void const *elem, va_list args),
		...);

/*
** Take lst elem with index.
** Take out the element at the given index in a list.
** Implemenation file : lst_take_elem.c
*/

void				*take_lst_elem(t_lst **lst, size_t index);

/*
** Variadic functions on list, with error reports.
** Same as above, but used with function which can fail, (memory allocation,
** etc). The list function shall report the error to its caller, so it will stop
** at the first error found.
** Able to modify content.
** Implementation file : f_lst_variadic_err.c
*/

t_bool				f_lstiterr_vas(
		t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		va_list args);
t_bool				f_lstiterr_va(
		t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		...);
t_bool				f_lstiterr_vas_const(
		t_lst const *lst,
		t_bool (*iter)(void const *elem, va_list),
		va_list args);
t_bool				f_lstiterr_va_const(
		t_lst const *lst,
		t_bool (*iter)(void const *elem, va_list),
		...);

/*
** List iterations
** Implementations file : f_lstiter.c
*/

void				f_lstiter(t_lst *lst, t_iter f);
t_bool				f_lstiterr(t_lst *lst, t_bool (*iter)(void *content));

/*
** Iterations with a functions that need the whole list as a reference
** parameters, to do stuff with it.
** Implementation file : lst_iter_on_itself.c
*/

t_bool				f_lst_insert_on_itself_va(
		t_lst *lst,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		...);
t_bool				f_lst_insert_on_itself_vas(
		t_lst *lst,
		void *(*insert)(void *content, t_lst const *itself, va_list),
		void (*destroy)(void **content),
		va_list args);

/*
** List transformation
** Implementation file : f_lstmap.c
*/

t_lst				*f_lstmap(
		t_lst const *lst,
		void *(*f)(void const *elem),
		t_destroy del);
t_lst				*f_lstmapi(
		t_lst const *lst,
		void *(*f)(void const *elem, unsigned int index),
		t_destroy del);
t_lst				*f_lstmap_vas(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		va_list args);
t_lst				*f_lstmap_va(
		t_lst const *lst,
		void *(*change)(void const*, va_list args),
		t_destroy destroy,
		...);

/*
** List iterators where the passed function use multiples items in the list
** Implementation_file : lst_iter_with_previous.c
*/

t_lst				*f_lst_mapinc_with_previous(
		t_lst *lst,
		void *(*iter)(void *i, void const *j),
		void *(*map)(void *i),
		t_destroy destroy);

/*
** List check elem
** Implementation file : f_lst_get_elem.c
*/

void				*f_lstsearch(const t_lst *list, const int ref,
		int (*match)(const void *elem));
void const			*f_lst_first_elem(const t_lst *lst);
t_lst				*advance_list(const t_lst *lst, size_t n_times);
t_lst				*lst_last_link(t_lst *lst);
void const			*get_lst_elem(t_lst const *lst, size_t index);

/*
** List array interactions
** Implementation file : f_lstarray.c
*/

size_t				f_lstarray_end_early(void *array, t_lst *lst, size_t size,
		t_bool (*put_lst_on_array)(const void *lst_content, void *array));
void				f_lstiterarray(void *array, t_lst *lst,
		void (*apply)(void *lst_content, void *array));
void				f_lstmaparray(const void *src, void *dst, t_lst *list,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier));

/*
** List validation
** Implementation file : f_lst_valid.c
*/

void				*f_lst_every_valid(t_lst const *list,
		t_bool (*test)(const void *content));
void				*f_lst_every_valid_va(t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args), ...);
void				*f_lst_every_valid_vas(t_lst const *list,
		t_bool valid_result,
		t_bool (*test)(const void *content, va_list args), va_list args);

/*
** List count whole list
** Implementation file : f_lst_count.c
*/

unsigned int		f_lst_len(const t_lst *lst);
unsigned int		f_lst_len_until(const t_lst *lst, void const *content);
int					f_lstsum_content(t_lst *list, int (*f)(const void *));
int					f_lstdosum(t_lst *list, int (*f)(void *));
size_t				f_lstmax(t_lst *list, size_t (*get_max)(const void *));

/*
** Put list in another list.
** Implementation file : list_cpy.c
**
** These returns *add_to on success, NULL on unexpected failure.
** (N.B. : *add_to == NULL is a possibility)
**
** lst_add_to_filter check before addition if the member is already in the list,
** and does not add if it is the case.
*/

t_lst				*lst_add_to(t_lst **add_to, t_lst const *add_from);
t_lst				*lst_add_to_filter(
		t_lst **add_to,
		t_lst const *add_from,
		t_bool *something_added);

/*
** Allocates a copy of a list, duplicating the references it holds
** Implementation file : lst_cpy_ref.c
*/

t_lst				*lst_cpy(t_lst const *lst);

/*
** Do from end
** Iterators going through the list backwards (by recursion)
** Useful for fonction that build data that can be reused by the leading links
** of the list
** Implementation file : lst_from_end.c
** TODO: Implement tests.
**
** Call the iter function on all the elem of the list, starting from the end.
**
** iter :
** - content is the content of that list link.
** - result_on_next will be equal to initial_result for the last link (and the
** first call to iter), then it will be equal to the return of the previous iter
** call.
*/

void				*lst_do_from_end(
		t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next));
void				*lst_do_from_end_va(t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next, va_list args),
		...);
void				*lst_do_from_end_vas(t_lst *lst,
		void *initial_result,
		void *(*iter)(void *content, void *result_on_next, va_list args),
		va_list args);

/*
** lst while
** Kind of a do_while loop, for lists
** Implementation file : lst_while.c
*/

t_bool				lst_do_while_err_vas(
		t_lst *lst,
		t_bool (*loop_body)(void *, va_list),
		t_bool (*loop_condition)(void const *, va_list),
		va_list args);
t_bool				lst_do_while_err_va(
		t_lst *lst,
		t_bool (*loop_body)(void *, va_list),
		t_bool (*loop_condition)(void const *, va_list),
		...);

#endif
