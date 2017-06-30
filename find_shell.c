/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:27:54 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:50 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_find_shell(t_opt *opts, char **env)
{
	int					i;

	i = 0;
	opts->shell = NULL;
	while (env[i])
	{
		if (ft_startswith(env[i], "SHELL="))
		{
			opts->shell = env[i] + 6;
			return (0);
		}
		++i;
	}
	opts->shell = "/bin/bash";
	return (0);
}
