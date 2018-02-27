/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arith_expr_test_destructors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:10:28 by mgautier          #+#    #+#             */
/*   Updated: 2018/02/02 19:10:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_interface.h"
#include <stdlib.h>

void	arith_expr_destroy(void **sub_expr)
{
	free(*sub_expr);
}

void	del_arith_token(void **token)
{
	destroy_token((t_token**)token);
}
