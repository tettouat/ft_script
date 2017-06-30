/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:09:52 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:26 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

sig_t					ft_signal(int s, void (*func)(int))
{
	struct sigaction	sa;
	struct sigaction	osa;
	sigset_t			sigintr;

	sigintr = 0;
	sa.sa_handler = func;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (!sigismember(&sigintr, s))
		sa.sa_flags |= SA_RESTART;
	if (sigaction(s, &sa, &osa) < 0)
		return (SIG_ERR);
	return (osa.sa_handler);
}
