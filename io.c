/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:28:38 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static void				st_input(t_opt *opts, int pid, char *buf)
{
	ft_signal(SIGWINCH, ft_sig_winch);
	ft_sig_winch(0);
	opts->zombi = pid;
	while (1)
	{
		ft_bzero(buf, 4096);
		if (-1 == (read(0, buf, 4096)))
			ft_end(pid);
		write(opts->master, buf, ft_strlen(buf));
	}
}

static void				st_output(t_opt *opts, char *buf)
{
	ft_signal(SIGUSR1, ft_sig_usr);
	while (1)
	{
		ft_bzero(buf, 4096);
		if ((read(opts->master, buf, 4096)) == -1)
			ft_end(0);
		write(1, buf, ft_strlen(buf));
		write(opts->fd, buf, ft_strlen(buf));
	}
}

int						ft_io(t_opt *opts, int pid_child)
{
	int					pid;
	char				buf[4096];

	if (-1 == (pid = fork()))
	{
		kill(pid_child, SIGKILL);
		_exit(-1);
	}
	if (!pid)
		st_output(opts, buf);
	else
		st_input(opts, pid, buf);
	return (0);
}
