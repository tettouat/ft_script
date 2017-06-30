/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:22:09 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:59:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_putstr(char const *s)
{
	int		nbr;

	if (s)
	{
		nbr = ft_strlen(s);
		write(1, s, nbr);
		return (nbr);
	}
	else
		return (ft_putstr("(null)"));
}
