/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:47:33 by alvieira          #+#    #+#             */
/*   Updated: 2023/12/12 22:20:45 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static void	ft_printhexa(unsigned int n, char c)
{
	char	*b_min;
	char	*b_mai;

	b_min = "0123456789abcdef";
	b_mai = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_printhexa(n / 16, c);
		ft_printhexa(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
		{
			if (c == 'x')
				ft_putchar(b_min[n]);
			if (c == 'X')
				ft_putchar(b_mai[n]);
		}
	}
}

int	ft_hex(unsigned int n, char c)
{
	ft_printhexa(n, c);
	return (ft_count(n));
}
