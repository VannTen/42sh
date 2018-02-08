/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ble-berr <ble-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:29:19 by ble-berr          #+#    #+#             */
/*   Updated: 2018/02/08 10:45:56 by ble-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	child_handler(int sigid)
{
	pid_t	child_pid;
	int		status;

	child_pid = waitpid(-1, &status, WNOHANG);
}
