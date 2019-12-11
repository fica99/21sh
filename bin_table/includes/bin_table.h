/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_table.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 18:06:10 by aashara-          #+#    #+#             */
/*   Updated: 2019/12/06 13:36:19 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIN_TABLE_H
# define BIN_TABLE_H

# define PREV_CUR_DIR 2
# define PREV_D ".."
# define CUR_D "."
# define FT_PATH_MAX 1000

typedef struct	s_table
{
	size_t		size;
	t_hash		**table;
}				t_table;

/*
**	hash_table.c
*/
void			init_bin_table(t_table *bin_table);
size_t			get_bin_table_size(char **path);
t_hash			**make_bin_table(char **path, size_t size);
void			free_table(t_table *table);

t_table			g_bin_table;
#endif
