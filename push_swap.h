/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:30:54 by reldahli          #+#    #+#             */
/*   Updated: 2024/03/19 13:30:57 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
//# include "../libft/inc/libft.h"
//# include "../libft/inc/ft_printf.h"

//define the data structure
//like a box for each node
typedef struct s_stach_node
{
	int					nbr;
	int					index;
	int					puh_cost;
	bool				above_median;
	bool				cheapet;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Handle errors

//Stack initiation

//Nodes initiation

//Stack utils

//commands

//Algrithms

#endif
