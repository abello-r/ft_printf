/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:08:08 by abello-r          #+#    #+#             */
/*   Updated: 2020/03/02 20:08:12 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_displayc(t_printf *format, int nb)
{
	int space;

	space = (format->width > 0) ? (format->width) : 0;
	space -= (format->width > 0 && format->tab != '-') ? 1 : 0;
	while (space-- > 0 && format->tab != '-')
		format->len_str += write(1, " ", 1);
	format->len_str += write(1, &nb, 1);
	while (space-- > 0 && format->tab == '-')
		format->len_str += write(1, " ", 1);
}
