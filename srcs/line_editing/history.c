/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:36:39 by aashara-          #+#    #+#             */
/*   Updated: 2019/07/02 15:44:44 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void		go_history(char *c, t_line *line)
{
	short	len;

	len = double_arr_len(line->history.history_buff);
	if (((*c == CTRL_R && len) || (g_flags & HISTORY_SEARCH)) && !(g_flags & TERM_QUOTES))
	{
		go_to_cord(line->cord->x_start, line->cord->y_start, STDIN_FILENO);
		ft_putstr_fd(tigetstr("ed"), STDIN_FILENO);
		if (!(g_flags & HISTORY_SEARCH))
		{
			ft_putstr_fd("(History search)'", STDIN_FILENO);
			g_flags |= HISTORY_SEARCH;
		}
		get_cur_cord(line->cord, 0);
		set_start_cord(line->cord);
		line->cord->pos = 0;
		find_history(c, line);
	}
	if (!(ft_strcmp(c, tigetstr("kcuu1"))) && len)
		history_up(line, len);
	else if (!(ft_strcmp(c, tigetstr("kcud1"))) &&
	line->history.history_index != len)
		history_down(line, len);
}

void	find_history(char *symbol, t_line *line)
{
	while (ft_strlen(line->history_search.buffer) + ft_strlen(symbol) >=
	(size_t)line->history_search.malloc_len)
		line->history_search.buffer = strnew_realloc_buf(line->history_search.buffer,
		line->history_search.malloc_len += NORMAL_LINE);
	ft_putstr_cord(line->history_search.buffer, line->cord);
	if (!print_printable(symbol, line->history_search.buffer, line->cord) && *symbol != CTRL_R)
	{
		g_flags &= ~HISTORY_SEARCH;
		go_to_cord(line->cord->x_start, line->cord->y_start, STDIN_FILENO);
		unset_start_pos(line->cord);
		get_cur_cord(line->cord, 0);
		go_left(17, line->cord);
		set_start_cord(line->cord);
		line->cord->pos = 0;
		ft_putstr_fd(tigetstr("ed"), STDIN_FILENO);
		ft_putstr_cord(line->buffer.buffer, line->cord);
		print_move(symbol, line->buffer.buffer, line->cord);
		ft_strclr(line->history_search.buffer);
		return ;
	}
	ft_putstr_fd("': ", STDIN_FILENO);
	get_cur_cord(line->cord, 0);
	line->cord->pos = 0;
	ft_putstr_cord(check_history(&line->history, &line->buffer, &line->history_search), line->cord);
}

char	*check_history(t_history *history, t_buff *buffer, t_buff *history_search)
{
	short	i;

	i = -1;
	while (history->history_buff[++i])
	{
		if (ft_strstr(history->history_buff[i], history_search->buffer) &&
		*(history_search->buffer) != '\0')
		{
			while (ft_strlen(history->history_buff[i]) >=
			(size_t)buffer->malloc_len)
				buffer->buffer = strnew_realloc_buf(buffer->buffer,
				buffer->malloc_len += NORMAL_LINE);
			ft_strclr(buffer->buffer);
			ft_strcat(buffer->buffer, history->history_buff[i]);
			break ;
		}
	}
	return (buffer->buffer);
}

void			history_up(t_line *line, short len)
{
	go_left(line->cord->x_cur - line->cord->x_start + ((line->cord->y_cur -
	line->cord->y_start) * line->cord->ws_col), line->cord);
	ft_putstr_fd(tigetstr("ed"), STDIN_FILENO);
	if (--(line->history.history_index) == len - 1)
		ft_strcat(line->save_buff.buffer, line->buffer.buffer + line->cord->pos);
	ft_strclr(line->buffer.buffer + line->cord->pos);
	while (ft_strlen(line->history.history_buff[line->history.history_index])+ ft_strlen(line->buffer.buffer) >=
	(unsigned)line->buffer.malloc_len)
		line->buffer.buffer = strnew_realloc_buf(line->buffer.buffer,
		line->buffer.malloc_len += NORMAL_LINE);
	ft_strcat(line->buffer.buffer, line->history.history_buff[(line->history.history_index)]);
	ft_putstr_cord(line->buffer.buffer + line->cord->pos, line->cord);
}

void			history_down(t_line *line, short len)
{
	char	*history_buffer;

	go_left(line->cord->x_cur - line->cord->x_start + ((line->cord->y_cur -
	line->cord->y_start) * line->cord->ws_col), line->cord);
	ft_putstr_fd(tigetstr("ed"), STDIN_FILENO);
	if (++(line->history.history_index) == len)
		history_buffer = line->save_buff.buffer;
	else
		history_buffer = line->history.history_buff[(line->history.history_index)];
	ft_strclr(line->buffer.buffer + line->cord->pos);
	while (ft_strlen(history_buffer) + ft_strlen(line->buffer.buffer) >=
	(unsigned)line->buffer.malloc_len)
		line->buffer.buffer = strnew_realloc_buf(line->buffer.buffer,
		line->buffer.malloc_len += NORMAL_LINE);
	ft_strcat(line->buffer.buffer, history_buffer);
	ft_putstr_cord(line->buffer.buffer + line->cord->pos, line->cord);
	if (line->history.history_index == len)
		ft_strclr(line->save_buff.buffer);
}
