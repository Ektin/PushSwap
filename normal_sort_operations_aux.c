/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort_operations_aux.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:53:24 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/02 16:58:30 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	swap_integers(int *a, int *b)
{
	int	num;

	num = *a;
	*a = *b;
	*b = num;
}

void	swap_pointers(t_node **a, t_node **b)
{
	t_node	*ptr;

	ptr = *a;
	*a = *b;
	*b = ptr;
}

void	settle_pointers(t_node *a, t_node *b)
{
	if (a->next == b)
	{
		a->next = b->next;
		b->next = a;
		b->prev = a->prev;
		a->prev = b;
	}
	else if (b->next == a)
	{
		b->next = a->next;
		a->next = b;
		a->prev = b->prev;
		b->prev = a;
	}
	else
	{
		swap_pointers(&a->next, &b->next);
		swap_pointers(&a->prev, &b->prev);
	}
}
