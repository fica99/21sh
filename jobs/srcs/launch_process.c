/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:37:26 by filip             #+#    #+#             */
/*   Updated: 2019/12/01 11:20:18 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	redir(int **red)
{
	while (*red)
	{
		if ((*red)[0] == -1)
			close((*red)[1]);
		dup2((*red)[0], (*red)[1]);
		red++;
	}
}

static void restore_fd(int *fd)
{
	if (fd[0] > -1)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			err_exit("42sh", "dup2() error", NULL, NOERROR);
		close(fd[0]);
	}
	if (fd[1] > -1)
	{
		if (dup2(fd[1], 1) < 0)
			err_exit("42sh", "dup2() error", NULL, NOERROR);
		close(fd[1]);
	}
	if (fd[2] > -1)
	{
		if (dup2(fd[2], STDERR_FILENO))
			err_exit("42sh", "dup2() error", NULL, NOERROR);
		close(fd[2]);
	}
}

int find_dup(int **redir, int fd)
{
	int fd2;
	while (*redir)
	{
		if ((*redir)[1] == fd)
		{
			if ((fd2 = dup(fd)) < 0)
				err_exit("42sh", "dup() error", NULL, NOERROR);
			return (fd2);
		}
		redir++;
	}
	return (-1);
}

static void	save_fd(int *fd, int **redir)
{	
	fd[0] = find_dup(redir, STDIN_FILENO);
	fd[1] = find_dup(redir, STDOUT_FILENO);
	fd[2] = find_dup(redir, STDERR_FILENO);
}

int	launch_builtin(t_process *p, int no_fork)
{
	t_builtin func;
	int fd[3];

	if (p->next && no_fork)
		return (-1);
	if (!(func = (t_builtin)get_hash_data(g_built_table.table, p->args[0], g_built_table.size)))
		return (-1);
	if (no_fork)
	{
		save_fd(fd, p->redir);
		redir(p->redir);
	}
	func(ft_darlen(p->args), p->args);
	if (no_fork)
		restore_fd(fd);
	return (0);
}

void	launch_process(t_process *p, pid_t pgid, int foreground)
{
	pid_t 	pid;
	char *fname;

	if (g_shell_is_interactive)
    {
    	pid = getpid();
    	if (pgid == 0)
			pgid = pid;
      	setpgid(pid, pgid);
      	if (foreground)
        	tcsetpgrp(g_shell_terminal, pgid);
      	set_sig_def();
    }
	if (!foreground) {
		/*close(STDOUT_FILENO);
		close(STDIN_FILENO);
		close(STDERR_FILENO);*/
	}
	if (p->next && p->next->inpipe)
		if (close (p->next->inpipe) < 0)
			err_exit("42sh", "close() error", NULL, NOERROR);
	if (p->inpipe != STDIN_FILENO)
	{
		if (dup2(p->inpipe, STDIN_FILENO) < 0)
			err_exit("42sh", "dup2() error", NULL, NOERROR);
		if (close(p->inpipe) < 0)
			err_exit("42sh", "close() error", NULL, NOERROR);
	}
	if (p->outpipe != STDOUT_FILENO)
	{
		if (dup2(p->outpipe, STDOUT_FILENO) < 0)
			err_exit("42sh", "dup2() error", NULL, NOERROR);
		if (close(p->outpipe) < 0)
			err_exit("42sh", "close() error", NULL, NOERROR);
	}
	redir(p->redir);
	if (!launch_builtin(p, FORK))
		exit (0);
	if (ft_strchr(p->args[0], '/'))
		fname = p->args[0];
	else if (!(fname = (char *)get_hash_data(g_bin_table.table, p->args[0], g_bin_table.size)))
		err_exit("42sh", "command not found", p->args[0], NOERROR);
	if (execve(fname, p->args, g_env.env) < 0)
		err_exit("42sh", "execve() error", p->args[0], NOERROR);
  	exit(1);
}
