/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:13:01 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/06 17:40:01 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	free_two_stacks(t_stack *stacka, t_stack *stackb, int opt_free)
{
	free_stack(stacka, opt_free);
	free_stack(stackb, opt_free);
	return (0);
}

void	init_two_stacks(t_stack *stacka, t_stack *stackb)
{
	init_stack(stacka);
	init_stack(stackb);
}

void	display_stack(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
	{
		write(1, "\n\nError display_stack with NULL\n\n", 34);
		return ;
	}
	node = stack->first;
	ft_printf("\n\n=============\n  display_stack with [%d] elements", stack->cnt);
	if (stack->cnt != 0)
		ft_printf(": [%d]((%d)) -->..--> [%d]((%d))\n", \
		stack->first->value, stack->first->ordinit, \
		stack->last->value, stack->last->ordinit);
	while (node != NULL)
	{
		if (node->prev != NULL)
			ft_printf("(%d)", node->prev->value);
		ft_printf("-->[%d]((%d))<%d>%p", node->value, node->ordinit, \
			node->rel_val, node);
		if (node->next != NULL)
			ft_printf("-->(%d)", node->next->value);
		ft_printf("\n");
		node = node->next;
	}
	ft_printf("\n  end display_stack\n\n================\n\n");
}

void	display_stack_cost(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
		return ;
	node = stack->first;
	ft_printf("\n\n==\n  display_stack_cost with [%d] elems", stack->cnt);
	if (stack->cnt != 0)
		ft_printf(": [%d] -->..--> [%d]\n", \
		stack->first->value, stack->last->value);
	while (node != NULL)
	{
		if (node->prev != NULL)
			ft_printf("[% 11d]", node->prev->value);
		else
			ft_printf("% 13s", "");
		ft_printf("-->[% d]((%d))(%d)<%d>", node->value, \
			node->glob_rel_val, node->rel_val, node->cost);
		if (node->next != NULL)
			ft_printf("-->[%d]", node->next->value);
		ft_printf("\n");
		node = node->next;
	}
	ft_printf("\n  end display_stack\n\n================\n\n");
}
