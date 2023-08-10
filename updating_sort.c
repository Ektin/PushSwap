/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:45:14 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 23:33:53 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort_large_updating(t_stack *stacka, t_stack *stackb, \
				int opt_write, int limit)
{
	t_sort_large	sort_large;
	int				pos;

	init_sort_large(&sort_large, stacka, stackb);
	set_glob_rel_val(stacka, 1);
	while (sort_large.pert_cnt_a != 0 && is_lim_ok(&sort_large, limit))
	{
		if (stacka->cnt <= 4)
		{
			sort_large.tot_oper_cnt += sort_small(stacka, stackb, opt_write);
			sort_large.pert_cnt_a = pert_cnt(stacka);
		}
		else
		{
			set_costs_updating(stacka);
			min_cost_index_in_stack(stacka, &pos);
			move_pos_up(&sort_large, pos, opt_write);
			do_pb(&sort_large, 3, opt_write);
		}
	}
	moving_everything_from_b_to_a_updating(&sort_large, opt_write);
	set_glob_rel_val(stacka, 2);
	return (sort_large.tot_oper_cnt);
}

void	set_glob_rel_val(t_stack *stack, int option)
{
	t_node	*node;

	if (NULL == stack)
		return ;
	node = stack->first;
	while (NULL != node)
	{
		if (1 == option)
			node->glob_rel_val = node->rel_val;
		else if (2 == option)
			node->rel_val = node->glob_rel_val;
		node = node->next;
	}
}

void	set_costs_updating(t_stack *stacka)
{
	int		ind;
	t_node	*node;
	int		cost;

	node = stacka->first;
	ind = 0;
	while (NULL != node)
	{
		if (ind <= (stacka->cnt - 1) / 2)
			node->cost = ind++;
		else if (ind < stacka->cnt)
			node->cost = stacka->cnt - ind++;
		else
			ft_printf("WHAT IS GOING ON HERE!!!\n\n\n\n");
		if (0 == node->rel_val)
			cost = 2;
		else if (node->rel_val <= stacka->cnt / 2)
			cost = 1 + 2 * node->rel_val;
		else if (node->rel_val > stacka->cnt / 2 && node->rel_val < stacka->cnt)
			cost = 1 + 2 * (stacka->cnt - node->rel_val);
		else
			ft_printf("WHAT IS GOING ON HERE???\n\n\n\n");
		node->cost += cost;
		node = node->next;
	}
}

int	min_cost_index_in_stack(t_stack *stack, int *pos)
{
	int		min;
	int		ind;
	t_node	*node;

	if (NULL == stack || NULL == stack->first)
	{
		*pos = -1;
		return (0);
	}
	node = stack->first;
	ind = 0;
	min = node->cost;
	*pos = 0;
	while (NULL != node)
	{
		if (min > node->cost)
		{
			min = node->cost;
			*pos = ind;
		}
		node = node->next;
		++ind;
	}
	return (min);
}
