/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/22 16:25:02 by tettouat          #+#    #+#             */
/*   Updated: 2015/05/22 16:25:14 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searchchr(int c)
{
	char	*buf;
	int		i;

	buf = "\n\v\t\r\f ";
	i = 0;
	while (i < 6)
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

float			ft_atoif(const char *str)
{
	float		result;
	float			is_neg;

	result = 0;
	is_neg = 1.0;
	while (ft_searchchr(*str))
		str++;
	while ((*str == '+' || *str == '-') && is_neg == 1.0)
	{
		if (*str == '-' || *(str + 1) == '+')
		{
			is_neg = -1.0;
			if (*(str - 1) == '+')
				str--;
		}
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * is_neg);
}
