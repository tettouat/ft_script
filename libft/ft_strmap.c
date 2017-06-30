/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:45:07 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:59:28 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) * sizeof(char));
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = (*f)(s[i]);
			i++;
		}
	}
	return (str);
}
