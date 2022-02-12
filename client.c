/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:59:59 by ocapers           #+#    #+#             */
/*   Updated: 2022/02/12 15:07:00 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	count_of_recevied(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%i\n", received);
		exit(0);
	}
}

void	send_message(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		i = 7;
		c = *message++;
		while (i >= 0)
		{
			if ((c >> i & 1) == 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			i--;
		}
	}
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	ft_printf("%s %d\n%s", "Sent: ", ft_strlen(argv[2]), "Received: ");
	signal(SIGUSR1, count_of_recevied);
	signal(SIGUSR2, count_of_recevied);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
