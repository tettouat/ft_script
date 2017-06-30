/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:12:16 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:31 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

char					*ft_get_path(t_opt *opts)
{
	int					i;

	i = 0;
	while (opts->env[i])
	{
		if (ft_startswith(opts->env[i], "PATH="))
			return (opts->env[i] + 5);
		++i;
	}
	return (NULL);
}

int						ft_nb_until_next(char *str)
{
	int					i;
	static int			first = 1;

	i = 1;
	while (str[i] && str[i] != ':')
		++i;
	if (!first && str[i])
		i += 1;
	first = 0;
	if (str[i] == ':')
		i += 1;
	return (i);
}
