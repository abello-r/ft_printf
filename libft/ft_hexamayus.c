/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexamayus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:36:01 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/14 12:35:37 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexamayus(unsigned int number)
{
	unsigned int	n;

	n = number;
	if (n > 16)
		ft_hexamayus(n / 16);
	n = n % 16;
	n = n < 10 ? n + '0' : n + 55;
	ft_putchar_fd(n, 1);
}
