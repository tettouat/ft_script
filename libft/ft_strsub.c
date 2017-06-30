/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:48:48 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:59:46 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh_cpy;
	size_t	i;

	fresh_cpy = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (fresh_cpy && (len <= ft_strlen(s)))
	{
		while (i < len)
		{
			fresh_cpy[i] = s[start];
			start++;
			i++;
		}
		fresh_cpy[i] = '\0';
	}
	return (fresh_cpy);
}
