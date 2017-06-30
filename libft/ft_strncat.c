/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:45:36 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:59:32 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*str;

	str = (char *)s1;
	while (*s1)
		s1++;
	while (n--)
	{
		if (!(*s1++ = *s2++))
			return (str);
	}
	*s1 = '\0';
	return (str);
}
