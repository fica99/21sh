/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:58:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/23 16:51:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETATOR_H
# define INTERPRETATOR_H

# include "../lex/includes/lex.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define DEF_HEREDOC_SIZE 10;
# define LRED_OPEN O_RDONLY
# define RRED_OPEN O_RDWR | O_CREAT | O_TRUNC
# define DRRED_OPEN O_RDWR | O_CREAT | O_APPEND
# define PERM_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# define INT_LEN 10
# define HEREDOC_FILE "/tmp/.42sh_heredoc"
# define INIT_AGGR_FD -5

typedef int(*redirect_func)(t_lex_tkn **, t_process *, int);

typedef struct	s_open_files 	
{
	int	*fd;
	size_t size;
}				t_open_files;

int         get_token_ind(t_lex_tkn **token_list, t_lex_tkn *token);
t_job       *job_new(void);
void        ft_free_jobs(t_job *j);
void        close_fds(t_job *first_job);
t_process	*add_process(void);
int			syntax_err(t_lex_tkn *token);
t_lex_tkn	**find_token(t_lex_tkn **list, int type);
void		parse(t_lex_tkn **tokens);
void		*ft_realloc(void *buf, size_t new_size);
char		**ft_strtok(char *s);
char		*ft_strccut(char *str, char c);
char		*ft_stricut(char *str, int i);
t_lex_tkn	**split_list(t_lex_tkn **token);
t_lex_tkn	**find_token(t_lex_tkn **list, int type);
t_job		*job_new(void);
int         redirect_list(t_lex_tkn **redir, t_process *cur_proc);

#endif