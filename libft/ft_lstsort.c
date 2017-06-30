/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:16:59 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:58:49 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst, int (*f)(t_list *, t_list *))
{
	int		sorted;
	t_list	*cur;

	sorted = 0;
	while (sorted == 0)
	{
		cur = lst;
		sorted = 1;
		while (cur)
		{
			if (f(cur, cur->next) == 1)
			{
				ft_lstswap(cur, cur->next);
				sorted = 0;
			}
			cur = cur->next;
		}
	}
}
