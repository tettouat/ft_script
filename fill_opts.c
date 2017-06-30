/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_opts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:33:22 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:43 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static int				st_acquire_opt(char *opt, t_opt *opts)
{
	int					i;
	int					len;

	i = 0;
	len = ft_strlen(opt);
	while (i < len)
	{
		if (opt[i] == 'a')
			opts->a = 1;
		else if (opt[i] == 'q')
			opts->q = 1;
		else
			return (ft_bad_option(opt[i]));
		++i;
	}
	return (0);
}

static int				st_acquire_file(char *file, t_opt *opts)
{
	if (0 == access(file, W_OK) || ENOENT == errno)
	{
		opts->file = file;
		return (0);
	}
	ft_putendl_fd("ft_script: err: Can't write to file.", 2);
	return (1);
}

static int				st_treat_arg(char *arg, t_opt *opts)
{
	if (ft_startswith(arg, "-") && ft_strlen(arg) > 1)
	{
		if (1 == st_acquire_opt(arg + 1, opts))
			return (1);
	}
	else
	{
		if (1 == st_acquire_file(arg, opts))
			return (1);
		return (42);
	}
	return (0);
}

int						ft_fill_opts(t_opt *opts, int ac, char **av)
{
	int					i;
	int					opts_turn;
	int					ret;

	opts->a = 0;
	opts->q = 0;
	opts->file = "typescript";
	opts->cmd = NULL;
	i = 1;
	opts_turn = 1;
	while (i < ac)
	{
		if (1 == (ret = st_treat_arg(av[i], opts)))
			return (1);
		if (42 == ret)
		{
			if (i + 1 < ac)
				opts->cmd = &av[i + 1];
			break ;
		}
		++i;
	}
	return (0);
}
