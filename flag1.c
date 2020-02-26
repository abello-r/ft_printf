/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 02:00:41 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/21 02:00:48 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t		ft_intlen(long nb)
{
	size_t count;

	count = 0;
	if(nb == 0)
	{
		count++;
		return(count);
	}
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while(nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return(count);
}

void		ft_spacex(t_printf *format, int nb)
{	
	int len;
	int space;
	int	zero;

	len = ft_intlen(nb);
	space = format->width - ((format->precision < len ) ? len : format->precision);
	space += (nb == 0 && format->precision == 0) ? len : 0;
	space -= (nb < 0) ? 1 : 0;
	zero = (nb < 0) ? (format->precision - len) + 1 : (format->precision - len);
	while(space > 0 && format->tab != '-')
	{	
		format->zero_space = ' ';
		format->len_str = write(1, &format->zero_space, 1);
		space--;
	}
	nb < 0 ? ft_putchar_fd('-', 1) : 0;
	while(zero-- > 0)
	{
		format->zero_space = '0'; 
		format->len_str = write(1, &format->zero_space, 1);
	}
	(format->precision == 0 && nb == 0) ? 0 : ft_putnbr_fd(nb, 1);
	while(space-- > 0)
	{
		format->len_str = write(1, " ", 1);
	}
}
