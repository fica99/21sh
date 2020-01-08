/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_init_temp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:35:08 by aashara-          #+#    #+#             */
/*   Updated: 2020/01/08 17:38:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static t_hash	**init_temp2(t_hash **table, int hash_size)
{
	char	symb[2];

	symb[1] = '\0';
	symb[0] = RL_K_CTRL_X;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_x, hash_size);
	symb[0] = RL_K_CTRL_V;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_v, hash_size);
	symb[0] = RL_K_CTRL_C;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_c, hash_size);
	symb[0] = RL_K_ENTER;
	table = push_hash(table, symb, (void*)&rl_k_enter, hash_size);
	symb[0] = RL_K_CTRL_H;
	table = push_hash(table, symb, (void*)&rl_k_bcsp, hash_size);
	symb[0] = RL_K_CTRL_R;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_r, hash_size);
	symb[0] = RL_K_BCSP;
	table = push_hash(table, symb, (void*)&rl_k_bcsp, hash_size);
	symb[0] = RL_K_CTRL_D;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_d, hash_size);
	symb[0] = RL_K_CTRL_J;
	table = push_hash(table, symb, (void*)&rl_k_ctrl_j, hash_size);
	symb[0] = RL_K_ESC;
	table = push_hash(table, symb, (void*)&rl_k_esc, hash_size);
	symb[0] = RL_K_CTRL_G;
	return (push_hash(table, symb, (void*)&rl_k_ctrl_g, hash_size));
}

t_hash			**init_temp(int hash_size)
{
	t_hash	**table;

	if (!(table = init_hash_table(hash_size)))
		rl_err("42sh", "malloc() error", ENOMEM);
	table = push_hash(table, RL_K_LFT, (void*)&rl_k_left, hash_size);
	table = push_hash(table, RL_K_RGHT, (void*)&rl_k_right, hash_size);
	table = push_hash(table, RL_K_HOME, (void*)&rl_k_home, hash_size);
	table = push_hash(table, RL_K_END, (void*)&rl_k_end, hash_size);
	table = push_hash(table, RL_K_CTRL_UP, (void*)&rl_k_ctrl_up, hash_size);
	table = push_hash(table, RL_K_CTRL_DOWN, (void*)&rl_k_ctrl_down,
	hash_size);
	table = push_hash(table, RL_K_CTRL_RIGHT, (void*)&rl_k_ctrl_right,
	hash_size);
	table = push_hash(table, RL_K_CTRL_LEFT, (void*)&rl_k_ctrl_left,
	hash_size);
	table = push_hash(table, RL_SHIFT_RIGHT, (void*)&rl_k_shift_right,
	hash_size);
	table = push_hash(table, RL_SHIFT_LEFT, (void*)&rl_k_shift_left,
	hash_size);
	table = push_hash(table, RL_K_DEL, (void*)&rl_k_del, hash_size);
	table = push_hash(table, RL_K_UP, (void*)&rl_k_up, hash_size);
	table = push_hash(table, RL_K_DOWN, (void*)&rl_k_down, hash_size);
	table = init_temp2(table, hash_size);
	return (table);
}
