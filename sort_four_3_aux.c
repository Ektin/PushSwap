/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_3_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:13:51 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 19:04:12 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort4_3(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (3 == f->a && 1 == f->b)
		return (sort4_3_1(stacka, stackb, f, opt_write));
	else if (3 == f->a && 2 == f->b)
		return (sort4_3_2(stacka, stackb, f, opt_write));
	else if (3 == f->a && 4 == f->b)
		return (sort4_3_4(stacka, stackb, f, opt_write));
	return (-2);
}

int	sort4_3_1(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (3 == f->a && 1 == f->b && 2 == f->c && 4 == f->d)
	{
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (4);
	}
	else if (3 == f->a && 1 == f->b && 4 == f->c && 2 == f->d)
	{
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (3);
	}
	return (-2);
}

int	sort4_3_2(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (3 == f->a && 2 == f->b && 1 == f->c && 4 == f->d)
	{
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (5);
	}
	else if (3 == f->a && 2 == f->b && 4 == f->c && 1 == f->d)
	{
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (2);
	}
	return (-2);
}

int	sort4_3_4(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (3 == f->a && 4 == f->b && 1 == f->c && 2 == f->d)
	{
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (2);
	}
	else if (3 == f->a && 4 == f->b && 2 == f->c && 1 == f->d)
	{
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (3);
	}
	return (-2);
}
