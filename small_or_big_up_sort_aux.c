/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_or_big_up_sort_aux.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:14:44 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 19:23:32 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	do_pb(t_sort_large *sort_large, int option, int opt_write)
{
	int		num;
	t_node	*node;

	recompute_pert_cnt(sort_large->stacka, sort_large->stackb, \
		"pb", &sort_large->pert_cnt_a);
	pb(sort_large->stacka, sort_large->stackb, opt_write);
	++sort_large->tot_oper_cnt;
	if (1 == option)
		++sort_large->min_a;
	else if (2 == option)
		--sort_large->max_a;
	else if (3 == option)
	{
		--sort_large->max_a;
		num = sort_large->stackb->first->rel_val;
		node = sort_large->stacka->first;
		while (NULL != node)
		{
			if (node->rel_val > num)
				--node->rel_val;
			node = node->next;
		}
	}
}

void	do_pa(t_sort_large *sort_large, int option, int opt_write)
{
	recompute_pert_cnt(sort_large->stacka, sort_large->stackb, \
		"pa", &sort_large->pert_cnt_a);
	pa(sort_large->stacka, sort_large->stackb, opt_write);
	++sort_large->tot_oper_cnt;
	if (1 == option)
		--sort_large->min_a;
	else if (2 == option)
		++sort_large->max_a;
}

void	do_ra(t_sort_large *sort_large, int opt_write)
{
	recompute_pert_cnt(sort_large->stacka, sort_large->stackb, \
		"ra", &sort_large->pert_cnt_a);
	ra(sort_large->stacka, sort_large->stackb, opt_write);
	++sort_large->tot_oper_cnt;
}

void	do_rra(t_sort_large *sort_large, int opt_write)
{
	recompute_pert_cnt(sort_large->stacka, sort_large->stackb, \
		"rra", &sort_large->pert_cnt_a);
	rra(sort_large->stacka, sort_large->stackb, opt_write);
	++sort_large->tot_oper_cnt;
}

void	move_pos_up(t_sort_large *sort_large, int pos, int opt_write)
{
	int		ind;

	if (0 <= pos && pos <= sort_large->stacka->cnt / 2)
	{
		ind = 0;
		while (ind++ < pos)
			do_ra(sort_large, opt_write);
	}
	else if (pos > sort_large->stacka->cnt / 2)
	{
		ind = 0;
		while (ind++ < sort_large->stacka->cnt - pos)
			do_rra(sort_large, opt_write);
	}
}
