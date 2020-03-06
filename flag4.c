/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:25:59 by abello-r          #+#    #+#             */
/*   Updated: 2020/03/04 19:26:00 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_espacios(int space, int zero, t_printf *format, unsigned int nb)
{
	int flag;

	flag = (nb < 0 && (space > format->precision && format->zero_space == '0'))
		? write(1, "-", 1) : 0;
	while (space > 0 && format->tab != '-')
	{
		format->len_str += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	while (zero-- > 0)
		format->len_str += write(1, "0", 1);
	(format->dot == '.' && nb == 0 && format->precision == 0)
		? 0 : ft_putnbr_fd(nb, 1);
	while (space-- > 0)
		format->len_str += write(1, " ", 1);
	format->len_str -= (format->dot == '.' && nb == 0 &&
		format->precision == 0) ? 1 : 0;
}

void		ft_display_u(t_printf *format, unsigned int nb)
{
	int len;
	int space;
	int	zero;

	len = ft_intlen(nb);
	format->len_str += len = ft_intlen(nb);
	space = format->width - ((format->precision < len)
		? len : format->precision);
	space -= (nb < 0 && format->precision >= len) ? 1 : 0;
	space += (format->dot == '.' && nb == 0
		&& format->precision == 0) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	ft_espacios(space, zero, format, nb);
}
