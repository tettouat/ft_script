/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:28:48 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:18 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_open_file(t_opt *opts)
{
	if (opts->a)
	{
		if (opts->file)
			opts->fd = open(opts->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			opts->fd = open("typescript", O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		if (opts->file)
			opts->fd = open(opts->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			opts->fd = open("typescript", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return (0);
}
