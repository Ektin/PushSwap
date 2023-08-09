/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_papb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:32:56 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 18:41:32 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	pa(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("pa\n");
	push_to_first_from_second(stacka, stackb);
	return ;
}

void	pb(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("pb\n");
	push_to_first_from_second(stackb, stacka);
	return ;
}
