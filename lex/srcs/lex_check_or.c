/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_check_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 18:27:21 by ggrimes           #+#    #+#             */
/*   Updated: 2019/12/08 18:40:08 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lex.h"

t_lex_tkn_type	lex_check_or(char **str, short is_word, size_t *pos)
{
	(void)str;
	if (is_word)
		return (T_NULL);
	(*pos)++;
	return (T_PIPE);
}
