/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:14:10 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:29 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_tcgetattr(int fd, struct termios *t)
{
	return (ioctl(fd, TIOCGETA, t));
}

int						ft_tcsetattr(int fd, struct termios *t)
{
	return (ioctl(fd, TIOCSETA, t));
}

void					ft_reset_term(t_opt *opts)
{
	ft_tcsetattr(0, &opts->term);
}

void					ft_raw(t_opt *opts)
{
	struct termios	s;

	ft_tcgetattr(0, &s);
	opts->term = s;
	s.c_lflag &= ~(ICANON | ECHO | ISIG);
	s.c_iflag &= ~(IXON | INLCR | IGNCR | ICRNL);
	s.c_cc[VMIN] = 1;
	s.c_cc[VTIME] = 0;
	ft_tcsetattr(0, &s);
}
