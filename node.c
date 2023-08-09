/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:32:24 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/07 20:25:28 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	set_node(t_node *node, int value, int ord)
{
	node->value = value;
	node->ordinit = ord;
	node->rel_val = -1;
	node->glob_rel_val = -1;
	node->cost = -1;
	node->prev = NULL;
	node->next = NULL;
	node->p = NULL;
	node->n = NULL;
	return ;
}

void	free_node(t_node *node)
{
	if (node == NULL)
	{
		write(1, "\n\nWARNING: free_node with empty node\n\n", 39);
		return ;
	}
	node->value = 0;
	node->ordinit = 0;
	node->rel_val = 0;
	node->glob_rel_val = 0;
	node->cost = 0;
	node->next = NULL;
	node->prev = NULL;
	node->n = NULL;
	node->p = NULL;
	free(node);
	return ;
}
