/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:11:02 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:39 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void					ft_end(int pid)
{
	t_opt				*opts;

	opts = ft_get_opts();
	if (pid)
		kill(pid, SIGUSR1);
	if (!opts->q)
	{
		write(1, "Script done, output file is ", 28);
		ft_putendl(opts->file);
		write(opts->fd, "\nScript done on ", 16);
		ft_date(opts->fd);
	}
	close(opts->fd);
	ft_reset_term(opts);
	_exit(0);
}
