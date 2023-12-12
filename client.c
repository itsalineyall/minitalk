/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:54:21 by alinevieira       #+#    #+#             */
/*   Updated: 2023/12/12 20:27:47 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

    i = 0;
	while (i < 8)
	{
		if ((c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		c = c >> 1;
		i++;
	}

}
void    ft_error(void)
{
    ft_printf("Wrong Format! Please, use: ./client (Server's PID) \"(Your Message)\"");
    exit(1);
}
int main(int argc, char **argv)
{
    int i;
    int pid;

    i = 0;
    if (argc != 3)
        ft_error();
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
    {
        send_bits(pid, argv[2][i]);
        i++;
    }
    send_bits(pid, '\n');
    return (0);
    
}