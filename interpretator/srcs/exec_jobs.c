/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_jobs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:23:13 by mmarti            #+#    #+#             */
/*   Updated: 2019/12/21 13:23:15 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	exec_jobs(void)
{
	t_job *j;

	if (!g_last_job || !g_last_job->next)
		j = g_first_job;
	else
	{
		g_last_job = g_last_job->next;
		j = g_last_job;
	}
	while (j)
	{
		g_last_job = j;
		launch_job(j, j->separator == T_AND ? 0 : 1);
		j = j->next;
	}
}
