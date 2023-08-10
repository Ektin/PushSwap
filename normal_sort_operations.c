/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:33:40 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/09 14:21:04 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	fill_n_p(t_stack *stack, int option)
{
	t_node	*node;
	int		num;

	if (NULL == stack)
		return ;
	if (1 == option)
	{
		node = stack->first;
		while (NULL != node)
		{
			node->n = node->next;
			node->p = node->prev;
			node = node->next;
		}
		stack->f = stack->first;
		stack->l = stack->last;
		return ;
	}
	node = stack->f;
	num = 0;
	while (NULL != node)
	{
		node->rel_val = num++;
		node = node->n;
	}
}

void	swap_nodes_n_p(t_node *node1, t_node *node2, t_stack *stack)
{
	swap_integers(&node1->value, &node2->value);
	swap_integers(&node1->ordinit, &node2->ordinit);
	swap_integers(&node1->rel_val, &node2->rel_val);
	swap_integers(&node1->glob_rel_val, &node2->glob_rel_val);
	swap_integers(&node1->cost, &node2->cost);
	if (NULL == node1->prev)
		stack->first = node2;
	else if (node1->prev != node2)
		node1->prev->next = node2;
	if (NULL == node1->next)
		stack->last = node2;
	else if (node1->next != node2)
		node1->next->prev = node2;
	if (NULL == node2->prev)
		stack->first = node1;
	else if (node2->prev != node1)
		node2->prev->next = node1;
	if (NULL == node2->next)
		stack->last = node1;
	else if (node2->next != node1)
		node2->next->prev = node1;
	settle_pointers(node1, node2);
}

t_node	*normal_sort_subroutine(t_pair *pair, t_stack *stack, int val, int opt)
{
	t_node	*i;
	t_node	*j;
	t_node	*prn;

	if (pair->beg == pair->end)
		return (pair->beg);
	i = pair->beg;
	j = pair->beg;
	prn = pair->end->n;
	while (i != prn)
	{
		if ((opt == 1 && i->value < val) || (opt == 2 && i->value <= val))
		{
			swap_nodes_n_p(i, j, stack);
			j = j->n;
		}
		i = i->n;
	}
	return (j);
}

void	normalsort(t_node *beg, t_node *end, t_stack *stack, int *error)
{
	t_node	*j1;
	t_node	*j2;
	t_pair	pair;
	int		val;

	if (stack == NULL || beg == NULL || end == NULL)
		return ;
	if (beg == end || (beg->n == end && beg->value < end->value))
		return ;
	if (beg->value == end->value)
		val = beg->value;
	else
		val = beg->value / 2 + end->value / 2;
	pair.beg = beg;
	pair.end = end;
	j1 = normal_sort_subroutine(&pair, stack, val, 1);
	pair.beg = j1;
	j2 = normal_sort_subroutine(&pair, stack, val, 2);
	if (j1 != j2 && j1->n != j2)
		*error = 1;
	if (j1 != beg)
		normalsort(beg, j1->p, stack, error);
	if (end->n != j2)
		normalsort(j2, end, stack, error);
}

void	display_stack_n_p(t_stack *stack)
{
	t_node	*node;

	if (stack == NULL)
	{
		write(1, "\n\nError display_stack with NULL\n\n", 34);
		return ;
	}
	node = stack->f;
	ft_printf("\n\n===========\nDisplay_Stack_n_p with [%d] elements", stack->cnt);
	if (stack->cnt != 0)
		ft_printf(": [%d]((%d)) -->..--> [%d]((%d))\n", \
		stack->f->value, stack->f->ordinit, \
		stack->l->value, stack->l->ordinit);
	while (node != NULL)
	{
		if (node->p != NULL)
			ft_printf("(%d)", node->p->value);
		ft_printf("-->[%d]((%d))<%d>", node->value, node->ordinit, \
					node->rel_val);
		if (node->n != NULL)
			ft_printf("-->(%d)", node->n->value);
		ft_printf("\n");
		node = node->n;
	}
	ft_printf("\n  end Display_Stack_n_p\n\n================\n\n");
}
