/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:16:45 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:58:48 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		if (content && content_size)
		{
			list->content_size = content_size;
			list->content = malloc(list->content_size);
			if (list->content)
				ft_memcpy(list->content, content, content_size);
		}
	}
	return (list);
}
