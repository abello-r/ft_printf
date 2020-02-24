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
	if(format->spaces > 0)
	{
		format->spaces -= ft_intlen(nb);
		while(format->spaces-- > 0 && format->tab == '-')
			format->len_str += write(1, &format->zero_space, 1);
		while(format->spaces-- > 0 && format->tab != '-')
			format->len_str += write(1, &format->zero_space, 1);
		ft_putnbr_fd(nb, 1);

	}
}
