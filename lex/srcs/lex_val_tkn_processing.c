/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_val_tkn_processing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: work <work@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:35:34 by ggrimes           #+#    #+#             */
/*   Updated: 2020/02/11 17:53:39 by work             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

static char		*lex_clip_tkn_value(t_lex_tkn *token,
	const char *str, size_t left_clip, size_t right_clip)
{
	size_t		len;
	char		*new_str;

	if (!token)
		return (NULL);
	if (token->start_pos + left_clip + right_clip > token->end_pos)
		return (ft_strsub(str, token->start_pos,
			token->end_pos - token->start_pos));
	len = token->end_pos - right_clip
		- (token->start_pos + left_clip);
	if (!(new_str = ft_strsub(str, token->start_pos
		+ left_clip, len)))
		return (NULL);
	return (new_str);
}

static size_t		lex_end_spases_size(const char *str, size_t pos)
{
	size_t		i;

	if (!str || !pos)
		return (0);
	i = 0;
	while (str[pos - 1] == ' ')
	{
		i++;
		pos--;
	}
	return (i);
}

static void		lex_clipping_tkn_value(t_lex_tkn *token, const char *str)
{
	char	*tkn_value;
	size_t	es_size;

	es_size = lex_end_spases_size(str, token->end_pos);
	if (token->type == T_ARITH_SUB)
		tkn_value = lex_clip_tkn_value(token, str, 3, es_size + 2);
	else if (token->type == T_QUOTES)
		tkn_value = lex_clip_tkn_value(token, str, 1, es_size + 1);
	else
		tkn_value = lex_clip_tkn_value(token, str, 0, es_size + 0);
	token->type  = (token->type == T_QUOTES) ? T_WORD : token->type;
	token->value = tkn_value;
}

void			lex_parse_tkn_value(t_lex_tkn *token, const char *str)
{
	if (token->type == T_ASSIGNMENT_WORD)
		lex_an_cut_quotes(token, str);
	else
		lex_clipping_tkn_value(token, str);
}
