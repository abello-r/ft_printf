/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memorypointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 11:59:46 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/14 12:45:50 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memorypointer(char *str)
{
	size_t	*x;

	ft_putstr_fd("0x", 1);
	x = (size_t *)&str;
	ft_hexa(*x);
}