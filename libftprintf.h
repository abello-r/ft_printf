/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:47:24 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/19 14:48:28 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct	s_printf
{
	char		*str;
	char		zero_space;
	char		tab;
	char		dot;
	int			width;
	int			precision;
	int			len_str;
	va_list		argptr;
} 				t_printf;

int		ft_printf(const char *s, ...);
size_t	ft_intlen(long nb);
void	ft_spacex(t_printf *format, int nb);
void	ft_formatletter(t_printf *format);
void	ft_setformat(t_printf *format);
void	ft_displayc(t_printf *format, int nb);

#endif
