/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:28:23 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/25 17:42:11 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_H
# define FT_SHELL_H

# include <termios.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <time.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include "libft.h"
# include "libstr.h"
# include "libdir.h"
# include "libdar.h"
# include "libfifo.h"
# include "libstack.h"
# include "libhash.h"
# include "term/term.h"
# include "environ/environ.h"
# include "bin_table/bin_table.h"
# include "history/history.h"
# include "prompt/prompt.h"
# include "error/error.h"
# include "macro/colour.h"
# include "line_editing/line_editing.h"
# include "lexer/lexer.h"
# include "parser/parser.h"
# include "interpretator/interpretator.h"
# include "reading/reading.h"
# include "builtins/cd.h"
# include "builtins/env.h"
# include "builtins/echo.h"
# include "builtins/setenv.h"
# include "builtins/unsetenv.h"
# include "builtins/hash.h"
# include "builtins/his.h"

#endif
