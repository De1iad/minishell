/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:51:34 by obibby            #+#    #+#             */
/*   Updated: 2022/09/21 10:49:45 by obibby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <sys/wait.h>
# include "../minishell.h"

typedef struct s_info {
	char	*buffer;
	int		stdout_fd;
	int		stdin_fd;
	int		infile_no;
	int		outfile_no;
	int		out_now;
	int		in_now;
	int		pipe_fd[2];
	int		total_ops;
	int		done_ops;
	char	**env;
	t_env	*env_ll;
	t_token	*token;
}	t_info;

typedef struct s_cmd {
	char	**cmds;
	char	*prog;
	int		total;
	t_info	*info;
}	t_cmd;

int		error_return(int id, void *mem, char *str);
int		ft_echo(t_token *token, t_info *info);
int		ft_pwd(t_token *token, t_info *info);
int		ft_cd(t_token *token, t_info *info);
int		exit_shell(t_mini *mini);
int		ft_env(t_token *token, t_info *info);
int		exec_cmds(t_token *token, t_info *info);
int		my_export(t_info *info);
int		my_unset(t_info *info);
char	*env_var(char *arg, char **env);
int		buff_to_buff(t_token *token, t_info *info, char *path);
void	init_array(t_mini *mini, t_info *info);
int		input_init(t_token *token, t_info *info);
int		output_init(t_token *token, t_info *info);
int		init_files(t_token *token, t_info *info);
int		set_fd(t_token *token, t_info *info);
int		shift_args(char **args);
int		revert_list(t_env *tmp, int i);
t_env	*get_last_node(t_env *env);

#endif