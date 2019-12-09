/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:14:25 by aashara-          #+#    #+#             */
/*   Updated: 2019/12/06 13:36:19 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		rl_init_terminfo(void)
{
	int		err;

	if (!isatty(STDIN_FILENO))
		rl_err("42sh", "stdin is not a terminal", UNDEFERR);
	if ((setupterm(0, STDIN_FILENO, &err) == ERR))
	{
		if (err == 1)
			rl_err("42sh", "setupterm() error", EHRDCPY);
		else if (err == 0)
			rl_err("42sh", "setupterm() error", ENTFND);
		else if (err == -1)
			rl_err("42sh", "setupterm() error", ENOTERMINFO);
	}
}

void		rl_init_rl_struct(t_readline *rl)
{
	rl->vi_hash = init_vi_hash(VI_HASH_SIZE);
	rl->rl_hash = init_emacs_hash(EMACS_HASH_SIZE);
	rl->noedit_hash = init_noedit_hash(NOEDIT_HASH_SIZE);
	rl_init_cord(&rl->cord);
	rl_init_buff(&rl->line);
	rl_init_buff(&rl->copy_buff);
	rl_init_buff(&rl->save_line);
	rl_init_buff(&rl->history.save_line);
	rl_init_buff(&rl->history.search);
	rl_init_history(&rl->history);
	rl->history.cur_command_nb = 1;
}

void		rl_init_cord(t_rl_cord *cord)
{
	cord->x_cur = 0;
	cord->x_start = 0;
	cord->ws_col = 0;
	cord->ws_row = 0;
	cord->y_cur = 0;
	cord->y_start = 0;
	cord->pos = 0;
	cord->highlight_pos = 0;
	cord->x_end = 0;
	cord->y_end = 0;
}

void		rl_init_buff(t_buff *buffer)
{
	if (!(buffer->buffer = ft_strnew(MAX_LINE_SIZE)))
		rl_err("42sh", "malloc() error", ENOMEM);
	buffer->malloc_len = MAX_LINE_SIZE;
	buffer->max_len = 0;
}
