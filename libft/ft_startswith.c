/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/16 05:41:44 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:59:09 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(const char *str, const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && str[i] == s[i])
	{
		i++;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}
