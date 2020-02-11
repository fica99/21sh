/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_tkn_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <work@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:34:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/02/11 16:44:54 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

static t_lex_tkn_type	lex_check_type_next(char **str,
	short is_word, size_t *pos)
{
	if ((*str)[*pos] == '\\')
		return (lex_check_bs(str, pos));
	else if ((*str)[*pos] == ';')
		return (lex_check_sep(str, is_word, pos));
	else if ((*str)[*pos] == RL_K_CTRL_D)
		return (lex_ctrl_d());
	else if ((*str)[*pos] == '$')
		return (lex_arith_sub(str, is_word, pos));
	else
		return (lex_check_other(str, is_word, pos));
}

t_lex_tkn_type			lex_check_type(char **str, short is_word, size_t *pos)
{
	if (!(*str)[*pos])
		return (lex_check_end(str, is_word, pos));
	else if (ft_isspace((*str)[*pos]))
		return (T_NULL);
	else if ((*str)[*pos] == RL_K_CTRL_C)
		return (lex_ctrl_c(str, NULL));
	else if (lex_is_quotation_marks(*str, *pos))
		return (lex_quotation_marks(str, is_word, pos));
	else if (ft_isalnum((*str)[*pos]))
		return (lex_check_alnum(str, is_word, pos));
	else if ((*str)[*pos] == '|')
		return (lex_check_or(str, is_word, pos));
	else if ((*str)[*pos] == '>')
		return (lex_check_greater(str, is_word, pos));
	else if ((*str)[*pos] == '<')
		return (lex_check_less(str, is_word, pos));
	else if ((*str)[*pos] == '&')
		return (lex_check_and(str, is_word, pos));
	else
		return (lex_check_type_next(str, is_word, pos));
}
