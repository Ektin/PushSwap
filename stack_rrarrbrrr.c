/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rrarrbrrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:08:01 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 19:53:14 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	rra(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		write(1, "rra\n", 4);
	revrotate(stacka);
	(void) stackb;
	return ;
}

void	rrb(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		write(1, "rrb\n", 4);
	revrotate(stackb);
	(void) stacka;
	return ;
}

void	rrr(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		write(1, "rrr\n", 4);
	revrotate(stacka);
	revrotate(stackb);
	return ;
}
