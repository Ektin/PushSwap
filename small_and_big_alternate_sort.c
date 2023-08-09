/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_and_big_alternate_sort.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:45:14 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 19:31:50 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort_large_small_big_alter_up(t_stack *stacka, t_stack *stackb, \
				int opt_write, int limit)
{
	t_sort_large	sort_large;
	int				cost1;
	int				cost2;

	init_sort_large(&sort_large, stacka, stackb);
	while (sort_large.pert_cnt_a != 0 && is_lim_ok(&sort_large, limit))
	{
		if (stacka->cnt <= 4)
		{
			sort_large.tot_oper_cnt += sort_small(stacka, stackb, opt_write);
			sort_large.pert_cnt_a = pert_cnt(stacka);
		}
		else
		{
			set_costs_and_move(&sort_large, &cost1, &cost2, opt_write);
		}
	}
	moving_everything_from_b_to_a(&sort_large, opt_write);
	return (sort_large.tot_oper_cnt);
}

void	set_costs_and_move(t_sort_large *sort_large, int *cost1, int *cost2, \
				int opt_write)
{
	int	pos1;
	int	pos2;

	pos1 = get_pos_of_elem_in_stack(sort_large->stacka, sort_large->min_a);
	*cost1 = pos1;
	if (*cost1 > sort_large->stacka->cnt - pos1) 
		*cost1 = sort_large->stacka->cnt - pos1;
	pos2 = get_pos_of_elem_in_stack(sort_large->stacka, sort_large->max_a);
	*cost2 = pos2;
	if (*cost2 > sort_large->stacka->cnt - pos2)
		*cost2 = sort_large->stacka->cnt - pos2;
	if (*cost1 + 2 <= *cost2 + 3)
	{
		move_pos_up(sort_large, pos1, opt_write);
		do_pb(sort_large, 1, opt_write);
	}
	else if (*cost1 + 2 > *cost2 + 3)
	{
		move_pos_up(sort_large, pos2, opt_write);
		do_pb(sort_large, 2, opt_write);
	}
}

void	moving_everything_from_b_to_a(t_sort_large *sort_large, int opt_write)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = sort_large->stacka;
	stackb = sort_large->stackb;
	while (stackb->cnt > 0)
	{
		if (stackb->first->rel_val < stacka->first->rel_val)
			do_pa(sort_large, 1, opt_write);
		else if (stackb->first->rel_val > stacka->last->rel_val)
		{
			do_pa(sort_large, 2, opt_write);
			do_ra(sort_large, opt_write);
		}
		else
			ft_printf("\n\nWHAT THE HECK IS GOING ON HERE!!!\n\n");
	}
}

int	is_lim_ok(t_sort_large const *sort_large, int limit)
{
	if (limit < 0 || sort_large->tot_oper_cnt < limit)
		return (1);
	return (0);
}
