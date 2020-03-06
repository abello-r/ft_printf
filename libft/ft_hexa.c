/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:44:11 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/14 12:30:03 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexa(size_t number)
{
	size_t n;

	n = number;
	if (n >= 16)
		ft_hexa(n / 16);
	n = n % 16;
	n = n < 10 ? n + '0' : n + 87;
	ft_putchar_fd(n, 1);
}
