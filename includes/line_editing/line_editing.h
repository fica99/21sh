/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:20:50 by filip             #+#    #+#             */
/*   Updated: 2019/05/31 20:28:55 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

void			print_read(char *c);
void			print_read_other(char *c, short len);
void			go_left(short i);
void			go_right(short i);
void			prev_word(char *buf, short len);
void			next_word(char *buf);
void			del_symb(char *buf, short len);
void			print_symb(char *c, char *buf, short len);
void            cut_copy_paste(char *c, short len);
#endif
