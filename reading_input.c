/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:27:35 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 16:12:26 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

void	read_input(int argc, char *argv[], t_stack *stack, int *err)
{
	int		i;
	char	**myargv;
	int		myargc;

	if (2 == argc)
	{
		myargc = ft_wc(argv[1], ' ');
		myargv = ft_split(argv[1], ' ');
	}
	else
	{
		myargv = &argv[1];
		myargc = argc - 1;
	}
	*err = 0;
	i = 0;
	while (myargv[i] != NULL && 0 == *err)
		add_node_to_stack(stack, ft_atoi_err(myargv[myargc - (++i)], err));
	if (2 == argc)
	{
		i = 0;
		while (myargv[i] != NULL)
			free(myargv[i++]);
		free(myargv);
	}
}
