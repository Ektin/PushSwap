/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_2_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:13:51 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 19:00:10 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort4_2(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (2 == f->a && 1 == f->b)
		return (sort4_2_1(stacka, stackb, f, opt_write));
	else if (2 == f->a && 3 == f->b)
		return (sort4_2_3(stacka, stackb, f, opt_write));
	else if (2 == f->a && 4 == f->b)
		return (sort4_2_4(stacka, stackb, f, opt_write));
	return (-2);
}

int	sort4_2_1(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (2 == f->a && 1 == f->b && 3 == f->c && 4 == f->d)
	{
		sa(stacka, stackb, opt_write);
		return (1);
	}
	else if (2 == f->a && 1 == f->b && 4 == f->c && 3 == f->d)
	{
		pb(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		pa(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (5);
	}
	return (-2);
}

int	sort4_2_3(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (2 == f->a && 3 == f->b && 1 == f->c && 4 == f->d)
	{
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (4);
	}
	else if (2 == f->a && 3 == f->b && 4 == f->c && 1 == f->d)
	{
		rra(stacka, stackb, opt_write);
		return (1);
	}
	return (-2);
}

int	sort4_2_4(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
					int opt_write)
{
	if (2 == f->a && 4 == f->b && 1 == f->c && 3 == f->d)
	{
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (3);
	}
	else if (2 == f->a && 4 == f->b && 3 == f->c && 1 == f->d)
	{
		ra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (4);
	}
	return (-2);
}
