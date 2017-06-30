/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 18:17:13 by tettouat          #+#    #+#             */
/*   Updated: 2015/02/16 14:58:50 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *lst1, t_list *lst2)
{
	void	*tmp_content;
	size_t	tmp_content_size;

	tmp_content = lst1->content;
	tmp_content_size = lst1->content_size;
	lst1->content = lst2->content;
	lst1->content_size = lst2->content_size;
	lst2->content = tmp_content;
	lst2->content_size = tmp_content_size;
}
