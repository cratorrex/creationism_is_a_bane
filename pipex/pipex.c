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
int	main(int count, char **vec)
{
	t_pipex	cntl;

	if (count >= (4 + 1))
	{
		cntl.infile = open(vec[0],O_RDONLY);
		cntl.outfile = open(vec[count - 1], O_RDONLY);
		//exit if either fails (-1);
		if (count >= (5 + 1) && ft_strmatch(vec[1], "here-doc"))
		{
			ft_printf("hello %i\n", count);
		}
		pid_t gra = fork();
		pid_t grati = fork();
		if (gra != 0)
			px_exec(vec);
		ft_printf("%i\n%i____\n\n", (int)gra, (int)grati);
	}
	else
	{
		ft_printf("Expected 4 arguments: file1, cmd1, cmd2, file2.\n");
	}
}

//to use execve we need to fork and dup and then pipe into???
