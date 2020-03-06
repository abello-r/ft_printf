/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:58:49 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/22 16:58:59 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_advance(t_printf *format)
{
	if (*format->str == 'd' || *format->str == 'i')
		ft_spacex(format, va_arg(format->argptr, int));
	else if (*format->str == 'c')
		ft_display_c(format, va_arg(format->argptr, int));
	else if (*format->str == 's')
		ft_display_s(format, va_arg(format->argptr, char *));
	else if (*format->str == 'u')
		ft_display_u(format, va_arg(format->argptr, unsigned int));
	else if (*format->str == 'x')
		ft_display_x(format, va_arg(format->argptr, unsigned int));
	else if (*format->str == 'X')
		ft_display_xmayus(format, va_arg(format->argptr, unsigned int));
	else if (*format->str == 'p')
		ft_display_pointer(format, va_arg(format->argptr, char *));
	else if (*format->str == '%')
		ft_display_c(format, 37);
}

void		ft_formatletter(t_printf *format)
{
	format->len_str = 0;
	while (*format->str)
	{
		if (*format->str == '%')
		{
			ft_setformat(format);
			ft_advance(format);
			if (*format->str != 'd' && *format->str != 'i' &&
				*format->str != 'c' && *format->str != 's' &&
				*format->str != 'u' && *format->str != 'x' &&
				*format->str != 'X' && *format->str != 'p' &&
				*format->str != '%')
				break ;
		}
		else
			format->len_str += write(1, format->str, 1);
		format->str++;
	}
	va_end(format->argptr);
}

int			ft_printf(const char *s, ...)
{
	t_printf	format;

	format.str = (char *)s;
	va_start(format.argptr, s);
	ft_formatletter(&format);
	va_end(format.argptr);
	return (format.len_str);
}
