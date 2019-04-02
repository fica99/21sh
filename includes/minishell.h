/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filip <filip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:28:23 by aashara-          #+#    #+#             */
/*   Updated: 2019/04/02 11:08:09 by filip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_errno.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdint.h> //lib for uint8_t
# include <fcntl.h>
# include <termios.h>
# include <limits.h>

char			**env_cp;
struct termios	savetty;

# define RUNNING 1

//signal.c
void			signalling(void);
void			signal_handler(int sign);
//reading.c
char			*read_prompt(void);
//get.c
short			get_count_var(char *arr);
char			*get_var(char *arr);
//print.c
void			print_environ(void);
void	        print_message(void);
void	        print_error(char *name, char *str, char *command, int p);
//make.c
char			**copy_double_arr(char **arr);
void			free_double_arr(char **arr);
char			*join_env(char *name, char *new_value);
pid_t			make_process(void);
//check.c
unsigned short	double_arr_len(char **arr);
char	        *check_new_line(char *arr);
//shell.c
void	        shell_start(void);
void	        find_command(char **args);
void			exec_command(char **args);
//parse.c
void			parse_string(char *buf);
char			**spec_symbols(char **args);
void			make_command(char *buf);
//flags.c
uint8_t			add_flag(uint8_t flags, char flag, uint8_t i);
uint8_t			is_flags(uint8_t flags, char flag);
uint8_t			find_flags(char **argv, unsigned short *i, uint8_t (fun)(char s));
//cd.c
void			cd(int argc, char **argv);
char			check_ch_dir(int argc , char **argv);
char			check_request(int argc, char  **argv);
//echo.c
void			echo(int argc, char **argv);
uint8_t			flag_n(char s);
//env.c
void 			env(int argc, char **argv);
char			check_set(char **argv);
//setenv.c
void 			ft_setenv(int argc, char **argv);
void	        set_env(char *name, char *new_value);
//unsetenv.c
void			ft_unsetenv(int argc, char **argv);
#endif
