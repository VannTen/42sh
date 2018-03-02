/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_expr_test_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:12:54 by mgautier          #+#    #+#             */
/*   Updated: 2018/03/02 18:41:49 by heynard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include "libft.h"
#include <stdlib.h>

void	*create_expr(void const *no_val)
{
	int	*expr;

	(void const*)no_val;
	expr = malloc(sizeof(*expr));
	if (expr != NULL)
		*expr = 0;
	return (expr);
}

t_bool	give_expr(void *v_expr, void *to_give)
{
	int *expr;
	int	*term;

	expr = v_expr;
	term = to_give;
	*expr = *expr + *term;
	free(term);
	return (TRUE);
}

void	*create_term(void const *no_val)
{
	int	*term;

	(void const *)no_val;
	term = malloc(sizeof(*term));
	if (term != NULL)
		*term = 1;
	return (term);
}

t_bool	give_term(void *v_term, void *to_give)
{
	int	*term;
	int	*factor;

	term = v_term;
	factor = to_give;
	*term = *term * *factor;
	free(factor);
	return (TRUE);
}

void	*create_factor(void const *no_val)
{
	int	*factor;

	(void const *)no_val;
	factor = malloc(sizeof(*factor));
	if (factor != NULL)
		*factor = 0;
	return (factor);
}
