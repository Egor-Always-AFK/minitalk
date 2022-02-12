/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocapers <ocapers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:59:39 by ocapers           #+#    #+#             */
/*   Updated: 2022/02/12 16:27:29 by ocapers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	symbol_handler(int sig, siginfo_t *info, void *idk)
{
	static int		i;
	static pid_t	user_pid;
	static int		symbol;

	(void)idk;
	if (!user_pid)
		user_pid = info->si_pid;
	if (sig == SIGUSR2)
		symbol += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (symbol == 0)
		{
			kill(user_pid, SIGUSR2);
			user_pid = 0;
			return ;
		}
		ft_printf("%c", symbol);
		symbol = 0;
		kill(user_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	t_sigaction;

	(void)argv;
	if (argc == 1)
	{
		ft_printf("%s %d\n", "PID:", getpid());
		t_sigaction.sa_sigaction = symbol_handler;
		t_sigaction.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &t_sigaction, NULL);
		sigaction(SIGUSR2, &t_sigaction, NULL);
		while (1)
			pause();
	}
	return (0);
}
