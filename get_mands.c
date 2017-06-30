/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mands.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:28:26 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:01 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_get_master_and_slave(t_opt *opts)
{
	static char			ptsname[128];
	struct stat			sbuf;
	char				*ret;
	int					pty;
	int					tty;

	if (-1 == (pty = open("/dev/ptmx", O_RDWR)))
		return (1);
	if (-1 == ioctl(pty, TIOCPTYGRANT))
		return (1);
	if (-1 == ioctl(pty, TIOCPTYUNLK))
		return (1);
	ret = NULL;
	if (-1 == ioctl(pty, TIOCPTYGNAME, ptsname))
		return (1);
	if (-1 == stat(ptsname, &sbuf))
		return (1);
	ret = ptsname;
	if (-1 == (tty = open(ret, O_RDWR)))
		return (1);
	opts->master = pty;
	opts->slave = tty;
	return (0);
}
