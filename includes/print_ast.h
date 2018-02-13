/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:36:14 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/13 12:55:09 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_AST_H
# define PRINT_AST_H

# include "shell_ast/program.h"

void	print_program(int fd, struct s_sh_program *const program);

#endif
