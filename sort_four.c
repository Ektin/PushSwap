/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:13:51 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 09:42:12 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	min_in_stack(t_stack *stack)
{
	int		min;
	t_node	*node;

	if (NULL == stack || NULL == stack->first)
		return (0);
	node = stack->first;
	min = node->rel_val;
	while (NULL != node)
	{
		if (min > node->rel_val)
			min = node->rel_val;
		node = node->next;
	}
	return (min);
}

int	sort4(t_stack *stacka, t_stack *stackb, int opt_write)
{
	t_four_numbers	f;
	int				res;
	int				min;

	min = min_in_stack(stacka);
	f.a = 1 + stacka->first->rel_val - min;
	f.b = 1 + stacka->first->next->rel_val - min;
	f.c = 1 + stacka->first->next->next->rel_val - min;
	f.d = 1 + stacka->first->next->next->next->rel_val - min;
	res = -1;
	if (1 == f.a && f.b <= 3)
		res = sort4_1_123(stacka, stackb, &f, opt_write);
	else if (1 == f.a && 4 == f.b)
		res = sort4_1_4(stacka, stackb, &f, opt_write);
	else if (2 == f.a)
		res = sort4_2(stacka, stackb, &f, opt_write);
	else if (3 == f.a)
		res = sort4_3(stacka, stackb, &f, opt_write);
	else if (4 == f.a)
		res = sort4_4(stacka, stackb, &f, opt_write);
	return (res);
}

int	sort4_1_123(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (1 == f->a && 2 == f->b && 3 == f->c && 4 == f->d)
		return (0);
	else if (1 == f->a && 2 == f->b && 4 == f->c && 3 == f->d)
	{
		pb(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		pa(stacka, stackb, opt_write);
		return (4);
	}
	else if (1 == f->a && 3 == f->b && 2 == f->c && 4 == f->d)
	{
		ra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (3);
	}
	else if (1 == f->a && 3 == f->b && 4 == f->c && 2 == f->d)
	{
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (2);
	}
	return (-2);
}

int	sort4_1_4(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (1 == f->a && 4 == f->b && 2 == f->c && 3 == f->d)
	{
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (2);
	}
	else if (1 == f->a && 4 == f->b && 3 == f->c && 2 == f->d)
	{
		pb(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		pa(stacka, stackb, opt_write);
		return (4);
	}
	return (-2);
}
