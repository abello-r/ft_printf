/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:36:35 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/21 11:36:39 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_setformat(t_printf *format)
{
	int nb;

	format->width = 0;
	format->precision = 0;
	format->tab = ' ';
	format->zero_space = ' ';


	while(!ft_isalpha(*format->str))
	{
		++format->str;
		if (*format->str == '-')
			format->tab = '-';
		if (*format->str == '0' && format->width == 0)
			format->zero_space = '0';
		if (*format->str == '*')
		{
			nb = va_arg(format->argptr, int);
			format->width = (nb < 0) ? (nb * -1) : nb;
			if (nb < 0)
				format->tab = '-';
		}
		if (ft_isdigit(*format->str) && *format->str != '0' && format->width == 0)
			format->width = ft_atoi(format->str);
		if (*format->str == '.')
		{
			format->str++;
			if (*format->str == '*')
				format->precision = va_arg(format->argptr, int);
			if (ft_isdigit(*format->str))
				format->precision = ft_atoi(format->str);
		}
	}
}
