/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:07:24 by paoroste          #+#    #+#             */
/*   Updated: 2017/10/19 22:58:51 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/srcs/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>

char		**g_envv;
void		out_shell(void);
void		affichage(void);
char		*parse_home_path(char *path, int reverse_parse);
char		*get_var(char *var);
int			exec_command(char **command);
void		signal_handler(int signo);
void		proc_signal_handler(int signo);
void		print_env(void);

#endif
