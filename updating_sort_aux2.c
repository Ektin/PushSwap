/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_sort_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:40:43 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 19:43:57 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	find_proper_pos_for_elem_in_stack(t_stack *stack, int num)
{
	t_node	*node;
	int		ind;

	if (NULL == stack || NULL == stack->first)
		return (-1);
	node = stack->first;
	ind = 0;
	if (num < node->glob_rel_val)
		return (0);
	while (NULL != node->next)
	{
		++ind;
		if (num < node->next->glob_rel_val)
			return (ind);
		node = node->next;
	}
	return (++ind);
}

void	moving_everything_from_b_to_a_updating(t_sort_large *sort_large, \
							int opt_write)
{
	int		pos;
	int		stackacnt;

	while (sort_large->stackb->cnt > 0)
	{
		pos = find_proper_pos_for_elem_in_stack(sort_large->stacka, \
			sort_large->stackb->first->glob_rel_val);
		stackacnt = sort_large->stacka->cnt;
		if (0 == pos)
			do_pa(sort_large, 3, opt_write);
		else if (pos > 0 && pos <= (stackacnt + 1) / 2)
		{
			do_if_first_half(sort_large, pos, opt_write);
		}
		else if (pos > (stackacnt + 1) / 2 && pos <= stackacnt)
		{
			do_if_second_half(sort_large, pos, stackacnt, opt_write);
		}
		else
			ft_printf("\n\nNOTHING ELSE IS POSSIBLE!!!\n\n");
	}
}

void	do_if_first_half(t_sort_large *sort_large, int pos, int opt_write)
{
	do_ra_mult_times(sort_large, pos - 1, opt_write);
	do_pa(sort_large, 3, opt_write);
	do_sa(sort_large, opt_write);
	do_rra_mult_times(sort_large, pos - 1, opt_write);
}

void	do_if_second_half(t_sort_large *sort_large, int pos, int stackacnt, \
							int opt_write)
{
	do_rra_mult_times(sort_large, stackacnt - pos, opt_write);
	do_pa(sort_large, 3, opt_write);
	do_ra_mult_times(sort_large, stackacnt - pos + 1, opt_write);
}
