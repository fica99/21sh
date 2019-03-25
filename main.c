/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:05:12 by aashara-          #+#    #+#             */
/*   Updated: 2019/03/25 20:00:19 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	pid_t	p;
	int		status;
	char *args[]={"/bin/ls",NULL};
	
	(void)argc;
	(void)argv;
	env_cp = copy_double_arr(environ);
	while (RUNNING)
	{
		ft_putstr(get_var("PWD", env_cp));
		ft_putchar(':');
    	p = fork();
		if (p < 0)
		{
			perror("Fork() error");
			exit(1);
		}
		if (p)
			waitpid(p, &status, 0);
		else
		{
			ft_putchar('\n');
			execve(args[0], args, env_cp);
		}
	}
	free_double_arr(env_cp);
	return (0);
}
