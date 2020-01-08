/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_k_vi3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:34 by aashara-          #+#    #+#             */
/*   Updated: 2020/01/08 16:51:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	rl_k_x_upper(t_readline *rl)
{
	char	symb[2];

	symb[1] = '\0';
	symb[0] = rl->line.buffer[rl->cord.pos];
	if ((g_rl_flags & RL_HISTORY_SEARCH_FLAG) ||
	(g_rl_flags & RL_HIGHLIGHT_FLAG))
		rl_disable_line(rl);
	if (rl_is_end_pos(rl->cord))
		return ;
	rl_check_str_mem(&rl->copy_buff, symb);
	ft_strcpy(rl->copy_buff.buffer, symb);
	rl_del_symb(rl->line.buffer, &rl->cord);
}

// void	rl_k_v(t_readline *rl)
// {
// 	char	*argv;
// 	char	path[MAX_LINE_SIZE];
// 	char	*content;

// 	if ((g_rl_flags & RL_HISTORY_SEARCH_FLAG) ||
// 	(g_rl_flags & RL_HIGHLIGHT_FLAG))
// 		rl_disable_line(rl);
// 	if (!(argv = get_env("VISUAL", ENV)))
// 		if (!(argv = get_env("EDITOR", ENV)))
// 			argv = "vi";
// 	ft_strcat(ft_strcpy(path, get_env("TMPDIR", ENV)), RL_VIFILE);
// 	ft_write_to_file(path, RL_OPEN_VIFILE, RL_PERM_VIFILE, rl->line.buffer);
// 	ft_strcat(ft_strcat(ft_strcpy(rl->line.buffer, argv), " "), path);
// 	rl_k_enter(rl);
// 	rl_set_non_canon_mode(&rl->non_canon_mode);
// 	check_valid_string(rl->line.buffer);
// 	if (!(content = ft_read_file(path)))
// 		rl_err("42sh", "reading error", ENOMEM);
// 	ft_strcpy(rl->line.buffer, content);
// 	ft_putendl(content);
// 	ft_strdel(&content);
// }

void	rl_k_f_lower(t_readline *rl)
{
	char	*pos;
	char	c[RL_MAX_BUFF + 1];

	if ((g_rl_flags & RL_HISTORY_SEARCH_FLAG) ||
	(g_rl_flags & RL_HIGHLIGHT_FLAG))
		rl_disable_line(rl);
	rl_read_handler(c, STDOUT_FILENO);
	if (ft_isprint(*c))
	{
		if ((pos = ft_strchr(rl->line.buffer + rl->cord.pos, *c)))
			rl_go_right(pos - (rl->line.buffer + rl->cord.pos), &rl->cord);
	}
}

void	rl_k_f_upper(t_readline *rl)
{
	short	new_pos;
	char	c[RL_MAX_BUFF + 1];

	if ((g_rl_flags & RL_HISTORY_SEARCH_FLAG) ||
	(g_rl_flags & RL_HIGHLIGHT_FLAG))
		rl_disable_line(rl);
	rl_read_handler(c, STDOUT_FILENO);
	if (ft_isprint(*c))
	{
		new_pos = rl->cord.pos;
		while (new_pos >= 0)
		{
			if (rl->line.buffer[new_pos] == *c)
			{
				rl_go_left(rl->cord.pos - new_pos, &rl->cord);
				break ;
			}
			--new_pos;
		}
	}
}
