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

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf
{
	char		*str;
	char		zero_space;
	char		tab;
	char		dot;
	int			width;
	int			precision;
	int			len_str;
	int			aux;
	va_list		argptr;
}				t_printf;

size_t			ft_intlen(long nb);
int				ft_printf(const char *s, ...);
void			ft_spacex(t_printf *format, int nb);
void			ft_formatletter(t_printf *format);
void			ft_setformat(t_printf *format);
void			ft_display_c(t_printf *format, int nb);
void			ft_display_s(t_printf *format, char *str);
void			ft_display_u(t_printf *format, unsigned int nb);
void			ft_display_x(t_printf *format, unsigned int nb);
void			ft_display_xmayus(t_printf *format, unsigned int nb);
void			ft_display_pointer(t_printf *ft_format, char *ch);

#endif
