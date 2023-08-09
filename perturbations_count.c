/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturbations_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:14:44 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 23:00:29 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	pert_cnt(t_stack *stack)
{
	int		cnt;
	t_node	*node;

	if (NULL == stack)
		return (0);
	if (0 == stack->cnt || 1 == stack->cnt)
		return (0);
	cnt = 0;
	node = stack->first;
	while (NULL != node->next)
	{
		if (node->rel_val > node->next->rel_val)
			++cnt;
		node = node->next;
	}
	return (cnt);
}

void	recompute_pert_cnt(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt)
{
	t_size_t	symb2cmp;

	symb2cmp = 4;
	if (0 == ft_strncmp(oper, "sa", symb2cmp))
	{
		recompute_pert_cnt_sa(stacka, stackb, pert_cnt);
	}
	else if (0 == ft_strncmp(oper, "pb", symb2cmp) || \
		0 == ft_strncmp(oper, "pa", symb2cmp))
	{
		recompute_pert_cnt_pb_pa(stacka, stackb, oper, pert_cnt);
	}
	else if (0 == ft_strncmp(oper, "ra", symb2cmp) || \
		0 == ft_strncmp(oper, "rra", symb2cmp))
	{
		recompute_pert_cnt_ra_rra(stacka, stackb, oper, pert_cnt);
	}
}

void	recompute_pert_cnt_ra_rra(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt)
{
	int			a;
	int			b;
	int			c;

	(void)stackb;
	if (NULL == stacka || stacka->cnt < 2)
		return ;
	a = stacka->first->rel_val;
	c = stacka->last->rel_val;
	if (0 == ft_strncmp(oper, "ra", (t_size_t)4))
	{
		b = stacka->first->next->rel_val;
		if (a > b)
			--*pert_cnt;
		if (c > a)
			++*pert_cnt;
	}
	else if (0 == ft_strncmp(oper, "rra", (t_size_t)4))
	{
		b = stacka->last->prev->rel_val;
		if (c > a)
			++*pert_cnt;
		if (b > c)
			--*pert_cnt;
	}
}

void	recompute_pert_cnt_sa(t_stack *stacka, t_stack *stackb, int *pert_cnt)
{
	int	a;
	int	b;
	int	c;

	(void)stackb;
	if (stacka->cnt < 2)
		return ;
	a = stacka->first->rel_val;
	b = stacka->first->next->rel_val;
	if (stacka->cnt >= 3)
	{
		c = stacka->first->next->next->rel_val;
		if ((a < b && b < c) || (a < b && c < a))
			++*pert_cnt;
		else if ((a > b && a < c) || (a > b && b > c))
			--*pert_cnt;
	}
	else if (2 == stacka->cnt)
	{
		if (a < b)
			++*pert_cnt;
		else if (b > a)
			--*pert_cnt;
	}
}

void	recompute_pert_cnt_pb_pa(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt)
{
	int			a;
	int			b;
	t_size_t	symb2cmp;

	symb2cmp = 4;
	if (0 == ft_strncmp(oper, "pb", symb2cmp))
	{
		if (stacka->cnt >= 2)
		{
			a = stacka->first->rel_val;
			b = stacka->first->next->rel_val;
			if (a > b)
				--*pert_cnt;
		}
	}
	else if (0 == ft_strncmp(oper, "pa", symb2cmp))
	{
		if (stacka->cnt >= 1 && stackb->cnt >= 1)
		{
			a = stackb->first->rel_val;
			b = stacka->first->rel_val;
			if (a > b)
				++*pert_cnt;
		}
	}
}
