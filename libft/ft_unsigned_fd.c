/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:31:24 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/15 18:37:29 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putchar(char x, int fd)
{
	write(fd, &x, 1);
}

void			ft_unsigned_fd(int n, int fd)
{
	unsigned i;

	i = n;
	if (i > 9)
	{
		ft_unsigned_fd(i / 10, fd);
		ft_putchar(i % 10 + 48, fd);
	}
	else
		ft_putchar(i % 10 + 48, fd);
}
