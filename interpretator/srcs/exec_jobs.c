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

void	exec_jobs(t_job *j)
{
	while (j)
	{
		if (!j->unactive)
			launch_job(j, 1);
		else
		{
			if (j->err_message)
				ft_putln(j->err_message);
		}
		j = j->next;
	}
}
