/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_or_big_up_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:14:44 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 00:19:34 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	initial_operations_with_stack(t_stack *stack)
{
	int	err;

	fill_n_p(stack, 1);
	err = 0;
	normalsort(stack->f, stack->l, stack, &err);
	if (1 == err)
		return (print_error_and_free_stack(stack, 0));
	fill_n_p(stack, 2);
	return (0);
}

void	init_sort_large(t_sort_large *sort_large, \
		t_stack *stacka, t_stack *stackb)
{
	sort_large->stacka = stacka;
	sort_large->stackb = stackb;
	sort_large->pert_cnt_a = pert_cnt(stacka);
	sort_large->min_a = 0;
	sort_large->max_a = stacka->cnt - 1;
	sort_large->tot_oper_cnt = 0;
}

int	sort_large_small_up(t_stack *stacka, t_stack *stackb, \
				int opt_write, int limit)
{
	t_sort_large	sort_large;
	int				pos;

	init_sort_large(&sort_large, stacka, stackb);
	while (sort_large.pert_cnt_a != 0 && \
		(limit < 0 || sort_large.tot_oper_cnt < limit))
	{
		if (stacka->cnt <= 4)
		{
			sort_large.tot_oper_cnt += sort_small(stacka, stackb, opt_write);
			sort_large.pert_cnt_a = pert_cnt(stacka);
		}
		else
		{
			pos = get_pos_of_elem_in_stack(sort_large.stacka, sort_large.min_a);
			move_pos_up(&sort_large, pos, opt_write);
			do_pb(&sort_large, 1, opt_write);
		}
	}
	while (stackb->cnt > 0)
		do_pa(&sort_large, 1, opt_write);
	return (sort_large.tot_oper_cnt);
}

int	sort_large_big_up(t_stack *stacka, t_stack *stackb, \
				int opt_write, int limit)
{
	t_sort_large	sort_large;

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
			move_pos_up(&sort_large, \
				get_pos_of_elem_in_stack(sort_large.stacka, sort_large.max_a), \
					opt_write);
			do_pb(&sort_large, 2, opt_write);
		}
	}
	while (stackb->cnt > 0)
	{
		do_pa(&sort_large, 2, opt_write);
		do_ra(&sort_large, opt_write);
	}
	return (sort_large.tot_oper_cnt);
}

int	get_pos_of_elem_in_stack(t_stack *stack, int rel_val)
{
	t_node	*node;
	int		index;

	if (NULL == stack)
		return (-2);
	index = 0;
	node = stack->first;
	while (NULL != node)
	{
		if (node->rel_val == rel_val)
			return (index);
		++index;
		node = node->next;
	}
	return (-1);
}
