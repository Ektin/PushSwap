/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:27:35 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/09 14:37:57 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	print_error_and_free_stack(t_stack *stack, int option)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(stack, option);
	return (1);
}
