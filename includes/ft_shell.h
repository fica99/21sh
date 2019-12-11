/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara- <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:28:23 by aashara-          #+#    #+#             */
/*   Updated: 2019/12/06 13:36:19 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHELL_H
# define FT_SHELL_H

# include <unistd.h>
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
# include "../sub/includes/sub.h"
# include "../jobs/includes/jobs.h"
# include "../term/includes/term.h"
# include "../environ/includes/environ.h"
# include "../bin_table/includes/bin_table.h"
# include "../error/includes/error.h"
# include "../ft_readline/includes/ft_readline.h"
# include "../lexer/includes/lexer.h"
# include "../parser/includes/parser.h"
# include "../interpretator/includes/interpretator.h"
# include "../builtins/includes/builtins.h"
#endif
