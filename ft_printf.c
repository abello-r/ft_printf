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
			ft_spacex(format,va_arg(format->argptr, int));
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

/*int			main(void)
{
	ft_printf("\n%0*.*d*", 42, 0, 0);
	   printf("\n%0*.*d*", 42, 0, 0);
	return (0);
}*/
