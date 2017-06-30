/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:25:58 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:32 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_cmd(t_opt *opts)
{
	char				cmd[4096];

	ft_bzero(cmd, 4096);
	if (1 == ft_find_path(opts, cmd))
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(opts->cmd[0], 2);
		return (1);
	}
	opts->cmd[0] = cmd;
	execve(opts->cmd[0], opts->cmd, opts->env);
	return (0);
}
