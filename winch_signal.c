/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:14:04 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:38 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void					ft_sig_winch(int sig)
{
	t_opt				*opts;
	struct winsize		ws;

	(void)sig;
	opts = ft_get_opts();
	signal(SIGWINCH, ft_sig_winch);
	if (ioctl(0, TIOCGWINSZ, &ws) != -1)
		ioctl(opts->master, TIOCSWINSZ, &ws);
}
