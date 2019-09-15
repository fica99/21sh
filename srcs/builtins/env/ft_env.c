/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filip <filip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:55:59 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/11 16:04:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

char	check_set(char **argv)
{
	short	j;

	j = 0;
	while (argv[++j])
	{
		if (!(ft_strchr(argv[j], '=')))
		{
			err(argv[0], argv[1], NULL, ENOENT);
			return (-1);
		}
	}
	return (1);
}

void	env(int argc, char **argv, char **env_cp)
{
	short	j;

	j = 0;
	(void)env_cp;
	if (check_set(argv) < 0)
		return ;
	print_environ();
	if (argc != 1)
	{
		j = 0;
		while (argv[++j])
		{
			ft_putstr_fd(argv[j], STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
	}
}
