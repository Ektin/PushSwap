/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_sort_aux1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:40:43 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 19:40:16 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	do_sa(t_sort_large *sort_large, int opt_write)
{
	recompute_pert_cnt(sort_large->stacka, sort_large->stackb, \
		"sa", &sort_large->pert_cnt_a);
	sa(sort_large->stacka, sort_large->stackb, opt_write);
	++sort_large->tot_oper_cnt;
}

void	do_ra_mult_times(t_sort_large *sort_large, int num, int opt_write)
{
	if (num <= 0)
		return ;
	while (num-- > 0)
		do_ra(sort_large, opt_write);
}

void	do_rra_mult_times(t_sort_large *sort_large, int num, int opt_write)
{
	if (num <= 0)
		return ;
	while (num-- > 0)
		do_rra(sort_large, opt_write);
}
