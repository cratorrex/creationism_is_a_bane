/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:49:07 by thtay             #+#    #+#             */
/*   Updated: 2026/04/09 16:49:08 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  insert {navyseal.copypasta}

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"
/*
	<unistd.h>
	close, read, write, access, dup, dup2, execve
	fork, pipe, unlink

	<stdlib.h> >>> malloc, free, exit
	
	<string.h> >>> strerror
*/
# include <errno.h>
// >>> && <stdio.h> >> perror
# include <fcntl.h>
// >>> open
# include <sys/wait.h>
// >>> wait, waitpid

typedef int	t_fpipe[2];

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*limit;

	int		pipe_size;

	t_fpipe	*pipette;
}	t_pipex;

int		ft_strmatch(char *vec, char *match);
int		ft_arrlen(char **s);

void	px_exec(char **vec, int v_i);
void	px_clean(t_pipex *cntl);
void	px_exit(char **split, char *join);
void	px_close_fd(void);

void	px_openi(t_pipex *cntl, char **vec);
void	px_mid(t_pipex *cntl, int i, char **vec);
void	px_closef(t_pipex *cntl, int i, char **vec);

void	px_hd_open(t_pipex *cntl, char **vec);
void	px_hd_mid(t_pipex *cntl, int i, char **vec);
void	px_hd_close(t_pipex *cntl, int i, char **vec);

char	*get_next_line_hd(int fd, char *limit);

#endif
