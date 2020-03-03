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

void		ft_formatletter(t_printf *format)
{
	format->len_str = 0;
	while (*format->str)
	{
		if (*format->str == '%')
		{
			ft_setformat(format);
				if (*format->str == 'd' || *format->str == 'i')
					ft_spacex(format,va_arg(format->argptr, int));
				else if (*format->str == 'c')
					ft_displayc(format,va_arg(format->argptr, int));
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

int			main(void)
{
	printf("\n|%d|\n", ft_printf("\n%-5c", ' '));
	   printf("\n|%d|\n", printf("\n%-5c", ' '));
	return (0);
}
