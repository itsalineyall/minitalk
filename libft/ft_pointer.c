/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:52:19 by alvieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:17:26 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned long long nb)
{
	int count;

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

static void	ft_printpointer(unsigned long long n)
{
	char			*base;

	base = "0123456789abcdef";

	if (n >= 16)
	{
		ft_printpointer(n / 16);
		ft_printpointer(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
			ft_putchar(base[n]);
	}
}

int ft_pointer(unsigned long long p)
{
    if (!p)
        return (ft_putstr("(nil)"));
    ft_putstr("0x");
    ft_printpointer(p);
    return(ft_count(p) + 2);
}
