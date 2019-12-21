/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara- <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:15:01 by ggrimes           #+#    #+#             */
/*   Updated: 2019/12/21 18:17:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	move_cursor_pos(short x, short y)
{
	char	*esc;

	if (!(esc = tigetstr("cup")))
		return ;
	esc = tparm(esc, x, y);
	ft_putstr_fd(esc, STDIN_FILENO);
}

void	move_cursor_down(short count)
{
	char	*esc;

	if (!(esc = tigetstr("cud")))
		return ;
	esc = tparm(esc, count);
	ft_putstr_fd(esc, STDIN_FILENO);
}

void	move_cursor_left(short count)
{
	char	*esc;

	if (!(esc = tigetstr("cub")))
		return ;
	esc = tparm(esc, count);
	ft_putstr_fd(esc, STDIN_FILENO);
}

void	move_cursor_right(short count)
{
	char	*esc;

	if (!(esc = tigetstr("cuf")))
		return ;
	esc = tparm(esc, count);
	ft_putstr_fd(esc, STDIN_FILENO);
}

void	move_cursor_up(short count)
{
	char	*esc;

	if (!(esc = tigetstr("cuu")))
		return ;
	esc = tparm(esc, count);
	ft_putstr_fd(esc, STDIN_FILENO);
}
