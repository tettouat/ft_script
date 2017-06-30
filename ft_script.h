/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_script.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/17 08:34:04 by tettouat          #+#    #+#             */
/*   Updated: 2014/07/17 18:43:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCRIPT_H
# define FT_SCRIPT_H

# include <termios.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <time.h>
# include "./libft/libft.h"

typedef struct			s_opt
{
	int					fd;
	int					a;
	int					q;
	char				*file;
	char				**cmd;
	char				*shell;
	int					master;
	int					slave;
	char				**env;
	int					zombi;
	struct termios		term;
}						t_opt;

t_opt					*ft_get_opts(void);
int						ft_script(t_opt *opts);
int						ft_fill_opts(t_opt *opts, int ac, char **av);
int						ft_find_shell(t_opt *opts, char **env);
int						ft_parse_error(char *opt);
int						ft_bad_option(char opt);
int						ft_open_file(t_opt *opts);
void					ft_date(int fd);
int						ft_get_master_and_slave(t_opt *opts);
int						ft_shell(t_opt *opts);
int						ft_cmd(t_opt *opts);
int						ft_find_path(t_opt *opts, char *cmd);
int						ft_io(t_opt *opts, int pid_child);
void					ft_raw();
void					ft_reset_term(t_opt *opts);
int						ft_tcsetattr(int fd, struct termios *t);
int						ft_tcgetattr(int fd, struct termios *t);
sig_t					ft_signal(int s, void (*func)(int));
void					ft_end(int pid);
void					ft_sig_child(int sig);
void					ft_sig_usr(int sig);
void					ft_sig_winch(int sig);
char					*ft_get_path(t_opt *opts);
int						ft_nb_until_next(char *str);

#endif
