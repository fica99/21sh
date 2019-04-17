/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filip <filip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 21:53:57 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/17 22:05:20 by filip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include<stdio.h>

char	*read_prompt()
{
	char	*str;

	if (!(str = ft_strnew(NORMAL_LINE)))
		print_error("minishell", "malloc() error", NULL, ENOMEM);
	set_input_mode();
	str = reading(str);
	reset_input_mode();
	ft_putchar_fd('\n', STDIN_FILENO);
	return (str);
}

char	*reading(char *buf)
{
	char	c[LINE_MAX + 1];
	uint8_t	n;

	n = 1;
	while (READING)
	{
		read_handler(c);
		if (g_flags & SHELL_SIGINT || g_flags & SHELL_SIGQUIT)
		{
			if (g_flags & SHELL_SIGINT)
				ft_strclr(buf);
			g_flags &= ~SHELL_SIGINT;
			g_flags &= ~SHELL_SIGQUIT;
		}
		if ((ft_strchr(c, '\n')))
			break;
		while (ft_strlen(buf) + ft_strlen(c) >= NORMAL_LINE * n)
			buf = strnew_realloc_buf(buf, &n);
		buf = make_buf_print(buf , c, &n);
	}
	return (buf);
}

void	read_handler(char *c)
{
	short	nb;

//	printf(" cord.prompt %d\n, cord.x_cur %d\n, cord.y_cur %d\n, cord.ws_col %d\n", cord.prompt, cord.x_cur, cord.y_cur, cord.ws_col);
	if ((nb = read(STDIN_FILENO, c, LINE_MAX)) < 0)
			print_error("minishell", "read() error", NULL, 0);
	c[nb] = '\0';
}

char	*make_buf_print(char *buf, char *c, uint8_t *n)
{
	int	len;

	*n = *n;
	len = cord.x_cur - cord.prompt + (cord.y_cur * cord.ws_col);
	if (!(ft_strcmp(c, LEFT)) && len > 1)
		go_left();
	else if (!(ft_strcmp(c, RIGHT)) && ((short)ft_strlen(buf) >= len))
		go_right();
	else
		check_key(c, buf, len);
	return (buf);
}

void			check_key(char *c, char *buf, int len)
{
	if (*c == BCSP && len > 1)
	{
		buf = ft_strdel_el(buf, --len);
		go_left();
		ft_putstr_cord(buf + len);
		ft_putstr_cord(" ");
		len = ft_strlen(buf + len) + 1;
		while (len--)
			go_left();
	}
	else if (ft_isprint(*c) && *c != BCSP)
	{
		buf = ft_stradd(buf, c, --len);
		ft_putstr_cord(buf + len);
		len = ft_strlen(buf + len);
	//	while (len--)
	//		go_left();
	}
}