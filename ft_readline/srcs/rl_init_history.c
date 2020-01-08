/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:44:51 by aashara-          #+#    #+#             */
/*   Updated: 2020/01/08 17:39:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static size_t	rl_find_hist_len(char *path)
{
	int		fd;
	int		res;
	size_t	len;
	char	*buff;

	if ((fd = open(path, RL_OPEN_HISTFILE, RL_PERM_HISTFILE)) == -1)
		rl_err("42sh", "open() error", UNDEFERR);
	len = 0;
	while ((res = get_next_line(fd, &buff)) > 0)
	{
		ft_strdel(&buff);
		++len;
	}
	if (res < 0)
		rl_err("42sh", "get_next_line() error", UNDEFERR);
	if (close(fd) == -1)
		rl_err("42sh", "close() error", UNDEFERR);
	return (len);
}

static void		rl_set_hist_buff(char *path, t_rl_history *history,
														size_t hist_len)
{
	size_t	len;
	int		fd;
	char	*buff;

	len = 0;
	if (!(history->history_buff = ft_darnew(history->histsize)))
		rl_err("42sh", "malloc() error", ENOMEM);
	if ((fd = open(path, RL_OPEN_HISTFILE, RL_PERM_HISTFILE)) == -1)
		rl_err("42sh", "open() error", UNDEFERR);
	if (hist_len > history->histsize)
		len = hist_len - history->histsize;
	while (len && (get_next_line(fd, &buff) > 0))
	{
		ft_strdel(&buff);
		--len;
	}
	while (len != history->histsize &&
	(get_next_line(fd, &history->history_buff[len]) > 0))
		++len;
	if (close(fd) == -1)
		rl_err("42sh", "close() error", UNDEFERR);
	history->hist_len = len;
	history->hist_index = len;
	history->cur_command_nb = 0;
}

void			rl_init_history(t_rl_history *history)
{
	char	*path;
	char	*home;
	char	*rl_histsize;
	char	*rl_histfilesize;

	if ((home = get_env("HOME", ENV)))
	{
		if (!(path = ft_strjoin(home, RL_HISTORY_FILE)))
			rl_err("42sh", "malloc() error", ENOMEM);
	}
	else
	{
		if (!(path = ft_strdup(RL_HISTORY_FILE)))
			rl_err("42sh", "malloc() error", ENOMEM);
	}
	set_env("HISTFILE", path, SET_ENV);
	if (!(rl_histsize = get_env("HISTSIZE", ENV)))
		rl_histsize = RL_HISTSIZE;
	set_env("HISTSIZE", rl_histsize, SET_ENV);
	if (!(rl_histfilesize = get_env("HISTFILESIZE", ENV)))
		rl_histfilesize = RL_HISTFILESIZE;
	set_env("HISTFILESIZE", rl_histfilesize, SET_ENV);
	rl_get_hist_size(history);
	rl_set_hist_buff(path, history, rl_find_hist_len(path));
	ft_strdel(&path);
}
