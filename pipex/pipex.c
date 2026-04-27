/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:49:15 by thtay             #+#    #+#             */
/*   Updated: 2026/04/09 16:49:16 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// basic requirements
// ./pipex {file1} {cmd1} {cmd2} {file2}
// ` $> < file1 cmd1 | cmd2 > file2 `
// "< txt.txt {CMD1} | {CMD2} > edit.txt"
//
//```
// wherein redirects::
//  < stdin | | > stdout
//   >  : Write File (Overwrite)
//   >> : Append File
//   <  : Takes input from file (instead of keyboard)
//	 << : Heredoc (Limiter symbol)
//```
//--
//```
// ./pipex txt.txt "grep 'lo'" "sed -r 's/r/--/g'" edit.txt
//   $>  < txt.txt grep 'lo' | sed -r 's/r/--/g' > edit.txt
//```
//
static void	px_init(t_pipex *cntl, int count, char **vec)
{
	int	i;

	i = 0;
	cntl->infile = open(vec[1],O_RDONLY);
	cntl->outfile = open(vec[count - 1], O_WRONLY);
	cntl->limit = "";
	cntl->pipette = ft_calloc(sizeof(t_fpipe) * (count - 2), 1);
	if (!cntl->pipette)
		exit(0);
	while (i < count - 2) //-4
	{
		pipe(cntl->pipette[i]);
		ft_printf("%i\n", i);
		i++;
	}
}

int	main(int count, char **vec)
{
	t_pipex	cntl;
	int	i;

	if (count >= (4 + 1))
	{
		px_init(&cntl, count, vec);
		// if (count >= (5 + 1) && ft_strmatch(vec[1], "here_doc"))
		// {
		// 	cntl.limit = vec[2];
		// }
/* 		int pipes[2];
 */		i = 0;
/* 		pipe(pipes);
 */		//exit if either fails (-1);
		
		pid_t gra = fork();
		//int fd = open(cntl.infile, O_RDONLY);
		dup2(cntl.infile, 0);
		close(cntl.infile);
		// pid_t grati = fork();
		//waitpid(0, 0, 0);
		if (gra == 0)
			px_exec(vec, cntl.pipette[i],cntl.pipette[i+1], i);
		i++;
		waitpid(gra, 0, 0);
		gra = fork();
		if (gra != 0)
			px_exec(vec, cntl.pipette[i],cntl.pipette[i+1], i);
		// ft_printf("%i\n%i____\n\n", (int)gra, (int)grati);
		close(cntl.pipette[i][0]);
		if (cntl.pipette[i][1] != 0)
			close(cntl.pipette[i][1]);

		waitpid(0, 0, 0);
		free(cntl.pipette);
		close(0);
	}
	else
	{
		ft_printf("Expected 4 arguments: file1, cmd1, cmd2, file2.\n");
	}
}

//to use execve we need to fork and dup and then pipe into???
