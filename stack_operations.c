/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:56:04 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/07/31 17:26:54 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	swap(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
		return ;
	if (stack->first == stack->last)
	{
		return ;
	}
	node = stack->first->next;
	stack->first->next = node->next;
	if (node->next != NULL)
		node->next->prev = stack->first;
	else
		stack->last = stack->first;
	stack->first->prev = node;
	node->next = stack->first;
	node->prev = NULL;
	stack->first = node;
	return ;
}

void	push_to_first_from_second(t_stack *stacka, t_stack *stackb)
{
	t_node	*node;

	if (stacka == NULL || stackb == NULL)
		return ;
	if (stackb->first == NULL)
		return ;
	node = stackb->first;
	if (stackb->first == stackb->last)
		stackb->last = NULL;
	stackb->first = node->next;
	--stackb->cnt;
	if (stackb->first != NULL)
		stackb->first->prev = NULL;
	if (stacka->first != NULL)
		stacka->first->prev = node;
	else
		stacka->last = node;
	node->prev = NULL;
	node->next = stacka->first;
	stacka->first = node;
	++stacka->cnt;
	return ;
}

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
		return ;
	if (stack->first == stack->last)
		return ;
	node = stack->first->next;
	node->prev = NULL;
	stack->last->next = stack->first;
	stack->first->next = NULL;
	stack->first->prev = stack->last;
	stack->last = stack->first;
	stack->first = node;
	return ;
}

void	revrotate(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
		return ;
	if (stack->first == stack->last)
		return ;
	node = stack->last->prev;
	node->next = NULL;
	stack->last->prev = NULL;
	stack->last->next = stack->first;
	stack->first->prev = stack->last;
	stack->first = stack->last;
	stack->last = node;
	return ;
}
