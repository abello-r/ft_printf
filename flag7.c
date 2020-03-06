/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:00:30 by abello-r          #+#    #+#             */
/*   Updated: 2020/03/05 17:00:32 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_lenhex_p(unsigned long nb)
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

void		ft_help(int space, t_printf *format, int nb, char *ch)
{
	int flag;

	while (space > 0 && format->tab != '-')
	{
		format->len_str += write(1, (format->zero_space != '0' ||
			(format->dot == '.' && format->precision >= 0)) ? " " : "0", 1);
		space--;
	}
	write(1, "0x", 2);
	while (format->aux-- > 0)
		format->len_str += write(1, "0", 1);
	(format->dot == '.' && ch == NULL && format->precision == 0)
		? 0 : ft_memorypointer(ch);
	while (space-- > 0)
		format->len_str += write(1, " ", 1);
	format->len_str -= (format->dot == '.' && ch == NULL &&
		format->precision == 0) ? 1 : 0;
}

void		ft_display_pointer(t_printf *format, char *ch)
{
	unsigned long	nb;
	int				space;
	int				len;

	len = ft_lenhex_p((unsigned long)ch) + 2;
	format->len_str += nb = ft_lenhex_p((unsigned long)ch) + 2;
	space = format->width - ((format->precision < len)
		? len : format->precision);
	space += (format->dot == '.' && nb == 0 && format->precision == 0) ? 1 : 0;
	space += (ch == NULL && format->dot == '.') ? 1 : 0;
	format->aux = format->precision - len + 2;
	ft_help(space, format, nb, ch);
}
