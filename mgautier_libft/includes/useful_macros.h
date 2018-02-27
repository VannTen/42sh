/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_macros.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:01:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 11:53:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_MACROS_H
# define USEFUL_MACROS_H
# include <stdlib.h>

/*
** Shortcuts
*/

# define RET_TEST(X) return ((X) ? EXIT_SUCCESS : EXIT_FAILURE)

/*
** Macros for compile-time checking
*/

# define ARRAY_LENGTH(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))

/*
** Static assertions
** That is meant to check condition on elements known at compile time (such as
** static variables and such)
** It is inspired from the Linux Kernel, and precisely, I found out the concept
** here :
** http://www.pixelbeat.org/programming/gcc/static_assert.html
*/

# define ASSERT(predicate) ((void)sizeof(char[1 - 2*!(predicate)]))

/*
** Macros for repeating a string a certain number of times, at compile-time.
** The main use if when using const string initializer including lots of
** repeating (and when they expand over multiples lines, it confuses the
** norminette).
**
** This hack is taken from an answer on Stack Overflow :
** https://stackoverflow.com/a/8556436/7208947
** The author profile :
** https://stackoverflow.com/users/968261/alexey-frunze
*/

# define REP0(X)
# define REP1(X) X
# define REP2(X) REP1(X) X
# define REP3(X) REP2(X) X
# define REP4(X) REP3(X) X
# define REP5(X) REP4(X) X
# define REP6(X) REP5(X) X
# define REP7(X) REP6(X) X
# define REP8(X) REP7(X) X
# define REP9(X) REP8(X) X
# define REP10(X) REP9(X) X

# define REP(HU,TE,ONE,X) REP##HU(REP10(REP10(X)))REP##TE(REP10(X))REP##ONE(X)

#endif
