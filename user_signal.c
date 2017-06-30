/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:10:06 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:34 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void					ft_sig_usr(int sig)
{
	t_opt				*opts;

	(void)sig;
	opts = ft_get_opts();
	close(opts->fd);
	ft_reset_term(opts);
	_exit(-1);
}
