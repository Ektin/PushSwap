/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:13:51 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/08 09:41:28 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort_small(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == stacka->cnt)
		return (0);
	if (2 == stacka->cnt)
		return (sort2(stacka, stackb, opt_write));
	else if (3 == stacka->cnt)
		return (sort3(stacka, stackb, opt_write));
	else if (4 == stacka->cnt)
		return (sort4(stacka, stackb, opt_write));
	return (-1);
}

int	sort2(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (stacka->cnt != 2)
	{
		ft_printf("Error: Wrong call of sort2\n");
		return (-1);
	}
	if (stacka->first->value > stacka->first->next->value)
	{
		sa(stacka, stackb, opt_write);
		return (1);
	}
	return (0);
}

int	sort3(t_stack *stacka, t_stack *stackb, int opt_write)
{
	t_four_numbers	f;
	int				res;
	int				min;

	if (stacka->cnt != 3)
		return (-1);
	min = min_in_stack(stacka);
	f.a = 1 + stacka->first->rel_val - min;
	f.b = 1 + stacka->first->next->rel_val - min;
	f.c = 1 + stacka->first->next->next->rel_val - min;
	res = -1;
	if (f.a <= 2)
	{
		res = sort3_12(stacka, stackb, &f, opt_write);
	}
	else if (3 == f.a)
	{
		res = sort3_3(stacka, stackb, &f, opt_write);
	}
	return (res);
}

int	sort3_12(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (1 == f->a && 2 == f->b && 3 == f->c)
	{
		return (0);
	}
	if (1 == f->a && 3 == f->b && 2 == f->c)
	{
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (2);
	}
	else if (2 == f->a && 1 == f->b && 3 == f->c)
	{
		sa(stacka, stackb, opt_write);
		return (1);
	}
	else if (2 == f->a && 3 == f->b && 1 == f->c)
	{
		rra(stacka, stackb, opt_write);
		return (1);
	}
	return (-2);
}

int	sort3_3(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (3 == f->a && 1 == f->b && 2 == f->c)
	{
		ra(stacka, stackb, opt_write);
		return (1);
	}
	else if (3 == f->a && 2 == f->b && 1 == f->c)
	{
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (2);
	}
	return (-2);
}
