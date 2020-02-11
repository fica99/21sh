/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_get_tkn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <work@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 15:22:06 by ggrimes           #+#    #+#             */
/*   Updated: 2020/02/11 17:47:00 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

t_lex_tkn			*lex_get_next_tkn(char **str, size_t pos)
{
	size_t				start_pos;
	t_lex_tkn_type		type;
	t_lex_tkn			*token;
	short				is_word;

	if (!str || !(*str))
		return (NULL);
	lex_preprocessing(*str, &pos);
	start_pos = pos;
	while (1)
	{
		is_word = (pos - start_pos > 0) ? 1 : 0;
		type = lex_check_type(str, is_word, &pos);
		if (type == T_ERR || type == T_CTRL_C)
			return (NULL);
		if (type != T_WORD)
			break ;
	}
	if (!(token = lex_new_tkn()))
		return (NULL);
	token->type = (type == T_NULL) ? T_WORD : type;
	token->class = lex_check_class(token->type);
	lex_fill_value_pos(token, *str, start_pos, pos);
	return (token);
}

void				lex_fill_value_pos(t_lex_tkn *token, char *str,
	size_t start_pos, size_t pos)
{
	if (!token || !str)
		return ;
	token->start_pos = start_pos;
	token->end_pos = pos;
	lex_parse_tkn_value(token, str);
}
