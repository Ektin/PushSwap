/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raddix_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:30:53 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/07 23:38:25 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	raddix_sort(t_stack *stacka, t_stack *stackb, int opt_write, int lim)
{
	t_sort_large	sort;
	int				ind;
	int				cnt;
	int				step;

	init_sort_large(&sort, stacka, stackb);
	cnt = stacka->cnt;
	ind = 0;
	step = 0;
	while ((cnt >> step) != 0 && sort.pert_cnt_a != 0 && is_lim_ok(&sort, lim))
	{
		ind = 0;
		while (ind++ < cnt)
		{
			if (((stacka->first->rel_val >> step) & 1) == 0)
				do_pb(&sort, 4, opt_write);
			else
				do_ra(&sort, opt_write);
		}
		while (NULL != stackb->first)
			do_pa(&sort, 4, opt_write);
		sort.pert_cnt_a = pert_cnt(stacka);
		++step;
	}
	return (get_tot_oper_cnt(&sort));
}

int	get_tot_oper_cnt(t_sort_large *sort_large)
{
	sort_large->pert_cnt_a = pert_cnt(sort_large->stacka);
	if (sort_large->pert_cnt_a != 0 && 0 > 1)
		return (-1);
	return (sort_large->tot_oper_cnt);
}
