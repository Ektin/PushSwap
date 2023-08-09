/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:45:35 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 22:56:56 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	init_stack(t_stack *stack)
{
	if (stack == NULL)
	{
		write(1, "\n\nError: illegal call of init_stack\n\n", 38);
		return ;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->f = NULL;
	stack->l = NULL;
	stack->cnt = 0;
	return ;
}

void	add_node_to_stack(t_stack *stack, int newval)
{
	t_node	*node;

	if (stack == NULL)
		write(1, "\n\nError in add_node_to_stack: stack is NULL\n\n", 46);
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
	{
		write(1, "\n\nError execution in add_node_to_stack: ", 41);
		write(1, "malloc failed\n\n", 16);
		return ;
	}
	set_node(node, newval, ++stack->cnt);
	if (stack->first == NULL)
	{
		stack->first = node;
		stack->last = node;
		return ;
	}
	node->next = stack->first;
	stack->first->prev = node;
	stack->first = node;
}

void	delete_first_node_from_stack(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
	{
		write(1, "\n\nError: illegal call of delete_first_node\n\n", \
			45);
		return ;
	}
	if (stack->first == NULL)
		return ;
	node = stack->first;
	stack->first = stack->first->next;
	--stack->cnt;
	if (stack->first != NULL)
		stack->first->prev = NULL;
	else
		stack->last = NULL;
	free_node(node);
	node = NULL;
	return ;
}

void	free_stack(t_stack *stack, int opt_free)
{
	if (stack == NULL)
	{
		write(1, "\n\nERROR: free_stack with NULL\n\n", 32);
		return ;
	}
	while (stack->first != NULL)
	{
		delete_first_node_from_stack(stack);
	}
	if (opt_free)
		free(stack);
	return ;
}

t_stack	*copy_stack(t_stack const *stack)
{
	t_stack	*res_stack;
	t_node	*orig_node;

	if (NULL == stack)
		return (NULL);
	res_stack = (t_stack *)malloc(sizeof(t_stack));
	if (NULL == res_stack)
		return (NULL);
	init_stack(res_stack);
	orig_node = stack->last;
	while (NULL != orig_node)
	{
		add_node_to_stack(res_stack, orig_node->value);
		res_stack->first->rel_val = orig_node->rel_val;
		res_stack->first->glob_rel_val = orig_node->glob_rel_val;
		res_stack->first->cost = orig_node->cost;
		res_stack->first->n = NULL;
		res_stack->first->p = NULL;
		orig_node = orig_node->prev;
	}
	res_stack->f = NULL;
	res_stack->l = NULL;
	return (res_stack);
}
