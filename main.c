/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:29:54 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:09 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int					main(int ac, char **av, char **env)
{
	t_opt			*opts;

	opts = ft_get_opts();
	opts->env = env;
	if (1 == ft_fill_opts(opts, ac, av))
		return (1);
	ft_find_shell(opts, env);
	if (1 == ft_script(opts))
		return (1);
	return (0);
}
