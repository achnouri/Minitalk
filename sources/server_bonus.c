/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:04 by achnouri          #+#    #+#             */
/*   Updated: 2025/02/01 02:28:48 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk_bonus.h"

void	tag(void)
{
	char	*tg;

	tg = "\n"\
		"\033[36m\t\t\t\t\t\t\t.___  ___.  __  .__   __.  __  "\
		".__________.    ___       __       __  ___ \n"
		"\t\t\t\t\t\t\t|   \\/   | |  | |  \\ "\
		"|  | |  | |          |   /   \\     |  |     |  |/  / \n"
		"\t\t\t\t\t\t\t|  \\  /  | |  | |   \\"\
		"|  | |  | `---|  |---`  /  ^  \\    |  |     |  '  /  \n"
		"\t\t\t\t\t\t\t|  |\\/|  | |  | |  . `  | "\
		"|  |     |  |     /  /_\\  \\   |  |     |    <   \n"
		"\t\t\t\t\t\t\t|  |  |  | |  | |  |\\   | "\
		"|  |     |  |    /  _____  \\  |  `----.|  .  \\  \n"
		"\t\t\t\t\t\t\t|__|  |__| |__| |__| \\__|"\
		" |__|     |__|   /__/     \\__\\ |_______||__|\\__\\ \n\n";
	ft_printf ("%s", tg);
}

static void	ft_handler(int signum, siginfo_t *info, void *v)
{
	static char		res;
	static int		index_bit;
	static pid_t	pid;

	(void)v;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = 0;
		res = 0;
		index_bit = 0;
	}
	if (signum == SIGUSR1)
		res |= (0x01 << index_bit);
	index_bit++;
	if (index_bit == 8)
	{
		if (res == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", res);
		index_bit = 0;
		res = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig_handler;
	int					pid;

	(void)av;
	if (ac != 1)
		return (ft_printf("\033[31mError ❌\033[37m\n"), 1);
	pid = getpid();
	tag();
	ft_printf("\033[1m\033[34m┌────────────┐\n");
	ft_printf("│ \033[36mPID: \033[1m\033[33m%d\033[0m\033[34m │\n", pid);
	ft_printf("└────────────┘\033[0m\n");
	ft_printf("\033[1m\033[34mwaiting a signal ...\033[1;37m");
	ft_printf("\n");
	sig_handler.sa_sigaction = ft_handler;
	sig_handler.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_handler.sa_mask);
	sigaction(SIGUSR1, &sig_handler, NULL);
	sigaction(SIGUSR2, &sig_handler, NULL);
	while (1)
		pause();
	return (0);
}
