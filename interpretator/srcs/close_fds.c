/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:21:50 by mmarti            #+#    #+#             */
/*   Updated: 2019/12/21 13:21:51 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

static void	cls_redir(int **red)
{
	int *tmp;

	while (*red)
	{
		tmp = *red;
		if (*tmp > 2)
			close(*tmp);
		if (tmp[1] > 2)
			close(tmp[1]);
		red++;
	}
}

void		close_fds(t_job *first_job)
{
	t_process *tmp;

	while (first_job)
	{
		tmp = first_job->first_process;
		while (tmp)
		{
			cls_redir(tmp->redir);
			tmp = tmp->next;
		}
		first_job = first_job->next;
	}
}
