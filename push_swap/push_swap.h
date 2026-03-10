/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:26:18 by thtay             #+#    #+#             */
/*   Updated: 2026/02/12 16:26:20 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//
// Debug Settings (-D)
//

//Makefile MOVES
// Display Moves (checks for div|3)
// [ 0 - Off ]  [ "| 1" - B ]  [ "| 2" - A ] //
# ifndef DISPLAY_MOVES
#  define DISPLAY_MOVES 0
# endif

//Makefile ERRORS
// Error Type (bool 0 or 1)
# ifndef ERROR_TYPE
#  define ERROR_TYPE 0
# endif

//
// end Debug Settings
//

//list locations
/* typedef struct s_stack
{
	struct t_list	*first;
	struct t_list	*last;
}	t_stack;

typedef struct s_rank
{
	int	i;
	int	j;
	int	j_ind;
}		t_rank;
 */

//Input Validation
int		**init_params(char **params, int count, int *error);
int		order_pass(int **params, int error);

//Processing (Handler)
int		**ps_start(int **stack_a);
int		**ps_r_init_stack(int **stack, int mode);
int		ps_stacklen(int **stack);
void	ps_rerank(int ***stack, int len, int len_i);

//Manual
int		isinstruction(char *buffer);

//Debug
void	ps_dsp(char *buf, int ***stack_a, int ***stack_b);

//Instructions
int		**ps_swap(int **stack);
int		**ps_rotate(int **stack);
int		**ps_rev_rotate(int **stack);
void	ps_push(int ***stack, int ***stack_dest);

//pre-radish sort
//Sort 2 < x < 8
void	ps_sort_nb3(int ***stack_a, int ***stack_b, int len);

//radish sort...
void	ps_sort_radix(int ***stack_a, int ***stack_b, int len);

//extra functions (not processor)
int		ft_atoi_e(const char *nptr, int *error);
int		ft_arrlen(char **s);
char	*ft_strjoin_free(char *s1, char *s2);
char	**ft_split_two(char const *s, char c1, char c2);

#endif
