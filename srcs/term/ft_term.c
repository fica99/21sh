/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 18:05:12 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/22 20:38:33 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int		main(int argc, char **argv, char **environ)
{
	init_global_var(argv, environ);
	if (argc == 1)
	{
		make_history_buff(&g_history);
		term_start();
		free_history(&g_history);
	}
	free_globar_var();
	return (EXIT_SUCCESS);
}

void	term_start(void)
{
	char	*buffer;

	init_terminfo();
	save_attr(&g_orig_mode);
	//init_line(&g_line);
	while (RUNNING)
	{
		g_flags = INIT_FLAGS;
	//	signal(SIGWINCH, win_handler);
		term_prompt();
	// 	read_prompt(term);
		check_valid_string(buffer);
		ft_memdel((void**)&buffer);
		if (g_flags & TERM_EXIT)
			break ;
	}
	//free_line(&g_line);
}

void	check_valid_string(char *buffer)
{
	t_node	*ast;

	if (!(g_flags & TERM_EXIT) && !(g_flags & TERM_SIGINT) && buffer)
	{
		ast = parser(buffer);
		if (!(g_parser_flags & PARSER_ERROR))
			interpret_ast(ast);
		free_ast(&ast);
		if (g_flags & TERM_FREE_HASH || g_flags & TERM_INIT_HASH)
		{
			free_bin_table(&g_bin_table);
			if (g_flags & TERM_INIT_HASH)
				init_bin_table(&g_bin_table);
		}
	}
}
