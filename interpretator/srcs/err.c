/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 07:49:47 by mmarti            #+#    #+#             */
/*   Updated: 2019/11/28 07:49:48 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

int syntax_err(t_lex_tkn *token)
{
	ft_putstr("42sh: ");
	ft_putstr("syntax error near unexpected token: ");
	ft_putstr(token->value);
	return (-1);
}
