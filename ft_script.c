/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:29:10 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:53 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static void				st_head(t_opt *opts)
{
	write(1, "Script started, output file is ", 31);
	ft_putendl(opts->file);
	write(opts->fd, "Script started on ", 18);
	ft_date(opts->fd);
}

static int				st_child(t_opt *opts)
{
	if (!opts->q)
		st_head(opts);
	close(opts->master);
	close(opts->fd);
	if (1 == ft_shell(opts))
		return (1);
	return (0);
}

int						ft_script(t_opt *opts)
{
	int					pid;

	if (1 == ft_open_file(opts))
		return (1);
	if (1 == ft_get_master_and_slave(opts))
	{
		ft_putendl_fd("Problem.", 2);
		return (1);
	}
	ft_signal(SIGCHLD, ft_sig_child);
	ft_raw(opts);
	pid = fork();
	if (pid == 0)
		st_child(opts);
	else
	{
		close(opts->slave);
		ft_io(opts, pid);
	}
	return (0);
}
