/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:17:11 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 14:22:21 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_AST_PIPELINE_H
# define SHELL_AST_PIPELINE_H

struct s_sh_pipeline
{
	void	*pipe_sequence;
	char	bang;
};

#endif
