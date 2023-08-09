/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sasbss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:46:31 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 18:39:34 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	sa(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("sa\n");
	swap(stacka);
	(void)stackb;
	return ;
}

void	sb(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("sb\n");
	swap(stackb);
	(void) stacka;
	return ;
}

void	ss(t_stack *stacka, t_stack *stackb, int opt_write)
{
	if (1 == opt_write)
		ft_printf("ss\n");
	swap(stacka);
	swap(stackb);
	return ;
}
