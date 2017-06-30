/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 06:15:10 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

void					ft_date(int fd)
{
	struct timeval		tp;
	char				*res;

	if (-1 == gettimeofday(&tp, NULL))
		return ;
	res = ctime(&tp.tv_sec);
	write(fd, res, ft_strlen(res));
}
