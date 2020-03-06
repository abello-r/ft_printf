/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:56:56 by abello-r          #+#    #+#             */
/*   Updated: 2020/03/04 21:56:59 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_lenhexa(size_t nb)
{
	size_t count;

	count = 0;
	if (nb == 0)
	{
		count++;
		return (count);
	}
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	return (count);
}

void		ft_aux(int space, int zero, t_printf *format, unsigned int nb)
{
	int flag;

	while (space > 0 && format->tab != '-')
	{
		format->len_str += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	while (zero-- > 0)
		format->len_str += write(1, "0", 1);
	(format->dot == '.' && nb == 0 && format->precision == 0)
		? 0 : ft_hexa(nb);
	while (space-- > 0)
		format->len_str += write(1, " ", 1);
	format->len_str -= (format->dot == '.' && nb == 0 &&
		format->precision == 0) ? 1 : 0;
}

void		ft_display_x(t_printf *format, unsigned int nb)
{
	int len;
	int space;
	int	zero;

	format->len_str += len = ft_lenhexa(nb);
	space = format->width - ((format->precision < len)
		? len : format->precision);
	space += (format->dot == '.' && nb == 0 && format->precision == 0) ? 1 : 0;
	zero = format->precision - len;
	ft_aux(space, zero, format, nb);
}
