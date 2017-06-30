/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:26:14 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:44:20 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_script.h"

int						ft_parse_error(char *opt)
{
	ft_putstr_fd("ft_script: err: Parse error near [", 2);
	ft_putstr_fd(opt, 2);
	ft_putendl_fd("]", 2);
	return (1);
}

int						ft_bad_option(char opt)
{
	ft_putstr_fd("ft_script: err: Unknown option [", 2);
	write(2, &opt, 1);
	ft_putendl_fd("]", 2);
	return (1);
}
