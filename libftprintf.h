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
	char		type;
	char		*str;
	char		zero_space;
	char		tab;
	int			spaces;
	int			precision;
	int			len_str;
	va_list		argptr;
} 				t_printf;

void	ft_spacex(t_printf *format, int nb);
int		ft_identify(t_printf *format, char c);
void	ft_setformat(t_printf *format);
int		ft_printf(const char *s, ...);

#endif
