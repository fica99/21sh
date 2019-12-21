/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_options2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara- <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:26:52 by aashara-          #+#    #+#             */
/*   Updated: 2019/12/21 18:17:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

char	**ac_add_options(char *path, char **options)
{
	char	**content;
	char	**new_options;
	char	*exec[3];

	if (!path)
		return (options);
	exec[0] = ".";
	exec[1] = "..";
	exec[2] = NULL;
	CHECK((content = ft_dir_content(path, 0)));
	CHECK((new_options = ft_dar_add(options, content, exec)));
	ft_free_dar(content);
	ft_free_dar(options);
	return (new_options);
}

void	clear_opts_args(char *arg, char *search_arg, char **options)
{
	ft_memdel((void**)&arg);
	ft_free_dar(options);
	ft_memdel((void **)&search_arg);
}
