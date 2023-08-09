/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_4_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:13:51 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 19:07:44 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort4_4(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (4 == f->a && 1 == f->b)
		return (sort4_4_1(stacka, stackb, f, opt_write));
	else if (4 == f->a && 2 == f->b)
		return (sort4_4_2(stacka, stackb, f, opt_write));
	else if (4 == f->a && 3 == f->b)
		return (sort4_4_3(stacka, stackb, f, opt_write));
	return (-2);
}

int	sort4_4_1(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (4 == f->a && 1 == f->b && 2 == f->c && 3 == f->d)
	{
		ra(stacka, stackb, opt_write);
		return (1);
	}
	else if (4 == f->a && 1 == f->b && 3 == f->c && 2 == f->d)
	{
		rra(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		rra(stacka, stackb, opt_write);
		return (4);
	}
	return (-2);
}

int	sort4_4_2(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (4 == f->a && 2 == f->b && 1 == f->c && 3 == f->d)
	{
		ra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (2);
	}
	else if (4 == f->a && 2 == f->b && 3 == f->c && 1 == f->d)
	{
		rra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (3);
	}
	return (-2);
}

int	sort4_4_3(t_stack *stacka, t_stack *stackb, t_four_numbers const *f, \
				int opt_write)
{
	if (4 == f->a && 3 == f->b && 1 == f->c && 2 == f->d)
	{
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		return (3);
	}
	else if (4 == f->a && 3 == f->b && 2 == f->c && 1 == f->d)
	{
		sa(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		ra(stacka, stackb, opt_write);
		sa(stacka, stackb, opt_write);
		return (4);
	}
	return (-2);
}
