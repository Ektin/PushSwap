/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rarbrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:08:01 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 18:42:42 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	ra(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("ra\n");
	rotate(stacka);
	(void) stackb;
	return ;
}

void	rb(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("rb\n");
	rotate(stackb);
	(void) stacka;
	return ;
}

void	rr(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("rr\n");
	rotate(stacka);
	rotate(stackb);
	return ;
}
