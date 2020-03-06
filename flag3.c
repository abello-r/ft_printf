/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:16:04 by abello-r          #+#    #+#             */
/*   Updated: 2020/03/03 17:16:07 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_decision(t_printf *format, char *str, int len)
{
	format->len_str += write(1, str, (format->dot == '.' &&
	format->precision == -1) ? 0 : len);
}

void		ft_display_s(t_printf *format, char *str)
{
	int space;
	int len;
	int len_null;

	str = (str == NULL) ? "(null)" : str;
	len = ft_strlen(str);
	len -= (format->precision > 0 &&
		format->precision < len) ? (len - format->precision) : 0;
	len -= (format->dot == '.' && format->tab == '-' &&
		format->precision == 0 && format->width == 0) ? len : 0;
	len -= (format->dot == '.' && format->tab != '-' &&
		format->precision == 0 && format->width == 0) ? len : 0;
	len -= (format->precision == 0 && format->width > 0 &&
		format->zero_space == ' ' && format->dot == '.') ? len : 0;
	space = (format->width > 0) ? (format->width - len) : 0;
	space += (format->tab == '-') ? 1 : 0;
	format->zero_space = (format->tab == '-' &&
		format->zero_space == '0') ? ' ' : format->zero_space;
	while (space-- > 0 && format->tab != '-')
		format->len_str += write(1, &format->zero_space, 1);
	(str == NULL) ? 0 : ft_decision(format, str, len);
	while (space-- > 0 && format->tab == '-')
		format->len_str += write(1, &format->zero_space, 1);
}
