/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:10:12 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:26 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void					ft_sig_child(int sig)
{
	t_opt				*opts;

	(void)sig;
	opts = ft_get_opts();
	if (!opts->q)
		write(1, "\n", 1);
	if (opts->zombi)
		ft_end(opts->zombi);
	else
		ft_end(0);
}
