/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:32:56 by alvieira          #+#    #+#             */
/*   Updated: 2023/12/11 18:18:13 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(unsigned int nb)
{
	int count;

	count = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	if (count == 0)
		return (1);
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = ft_count(n);
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(n + 48);
	return (count);
}