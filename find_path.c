/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:27:42 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:47 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

static char				*st_extract(char *src, char *dest)
{
	int					i;

	ft_bzero(dest, 4096);
	i = 0;
	while (src[i] && src[i] != ':')
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

void					st_join(char *path, char *cmd)
{
	int					i;
	int					y;

	i = ft_strlen(path);
	y = 0;
	path[i++] = '/';
	while (cmd[y])
	{
		path[i] = cmd[y];
		++i;
		++y;
	}
}

static int				st_simple_cmd(t_opt *opts, char *cmd)
{
	if (0 == access(opts->cmd[0], X_OK))
	{
		ft_strcpy(cmd, opts->cmd[0]);
		return (0);
	}
	else
		return (1);
}

int						ft_find_path(t_opt *opts, char *cmd)
{
	char				*path;
	char				tmp[4096];
	int					len;
	int					i;

	if (-1 != ft_indexof(opts->cmd[0], '/'))
		return (st_simple_cmd(opts, cmd));
	if (NULL == (path = ft_get_path(opts)))
		return (1);
	i = 0;
	while (path[i])
	{
		len = ft_nb_until_next(&(path[i]));
		st_join(st_extract(&(path[i]), tmp), opts->cmd[0]);
		if (0 == access(tmp, X_OK))
		{
			ft_strcpy(cmd, tmp);
			return (0);
		}
		i += len;
	}
	return (1);
}
