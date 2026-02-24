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

// Display Moves (checks for div|3)
// [ 0 - Off ]  [ "| 1" - B ]  [ "| 2" - A ] //
# ifndef DISPLAY_MOVES
#  define DISPLAY_MOVES 0
# endif

// Error Type (bool 0 or 1)
# ifndef ERROR_TYPE
#  define ERROR_TYPE 0
# endif

//
// end Debug Settings
//

//list locations
typedef struct s_stack
{
	struct t_list	*first;
	struct t_list	*last;
}	t_stack;

char	**init_params(char **params, int count, char *error);

//extra functions (not processor)
int		ft_atoi_e(const char *nptr, char *error);
size_t	ft_arrlen(char **s);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
