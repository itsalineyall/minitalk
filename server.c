/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alinevieira <alinevieira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:55:13 by alinevieira       #+#    #+#             */
/*   Updated: 2023/12/11 18:20:21 by alinevieira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum)
{
    static int  i = 0;
    static char c = 0;

    if (signum == SIGUSR1)
        c = c | (1 << i);
    i++;
    if (i == 8)
    {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction    sa;

    int                 pid;

    pid = getpid();
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = &sig_handler;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Hello! The ID of this process is: %d \n", pid); // ALTERAR DEPOIS
    while (1)
        pause();
    return (0);
}