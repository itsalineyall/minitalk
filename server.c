/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvieira <alvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:13 by alinevieira       #+#    #+#             */
/*   Updated: 2023/12/12 00:54:05 by alvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signal)
{
    static int  i;
    static char bits;

    i = 0;
    bits = 0;

    if (signal == SIGUSR1)
        bits = bits | (1 << i);
    i++;
    if (i == 8)
    {
        write(1, &bits, 1);
        i = 0;
        bits = 0;
    }
}

int main(int argc, char **argv)
{
    int pid;

    (void)argv;
    if (argc != 1)
    {
        ft_printf("Error! Please, execute only -> ./server\n");
        return (0);
    }
    pid = getpid();

    ft_printf("Hey! The PID of this process is: %d \n", pid);
    
    while (1)
    {
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
    }
    return (0);
}