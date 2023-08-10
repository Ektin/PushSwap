/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:13:01 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 15:47:52 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	main(int argc, char *argv[])
{
	int		err;
	t_stack	stacka;
	t_stack	stackb;
	int		option_random;
	char	file_name[100];

	ft_strlcpy(file_name, "example9.txt", 50);
	option_random = 0;
	err = 0;
	if (0 == option_random && 1 == argc)
		return (0);
	init_two_stacks(&stacka, &stackb);
	if (0 == option_random)
		read_input(argc, argv, &stacka, &err);
	else if (1 == option_random)
		generate_random_input(argc, argv, &stacka, file_name);
	if (1 == err || (2 == argc && 0 == stacka.cnt))
		return (print_error_and_free_stack(&stacka, 0));
	if (1 == initial_operations_with_stack(&stacka))
		return (1);
	if (stacka.cnt <= 4)
		sort_small(&stacka, &stackb, 1);
	else if (stacka.cnt >= 5)
		sort_large(&stacka, &stackb);
	return (free_two_stacks(&stacka, &stackb, 0));
}

/*
other options for sorting algorithms:
on line ~40, choose between
a) sort_large(&stacka, &stackb);
	it chooses the best between sort_large_updating and raddix_sort.
b) sort_large_small_big_alter_up(&stacka, &stackb, 1, -1); 
	performance: 100->1.1K, 500->23K, 1K->89K
c) sort_large_small_up(&stacka, &stackb, 1, -1);
	performance: 100->1.7K, 500->34K, 1K->131K
d) sort_large_big_up(&stacka, &stackb, 1, -1);
	performance: 100->1.7K, 500->34K, 1K->135K
e) sort_large_updating(&stacka, &stackb, 1, -1);
	performance: 100->731, 500->10K, 1K->31K, 10K->1.2M
f) raddix_sort(&stacka, &stackb, 1, -1);

To generate random numbers, 
1) change option_random = 1 on line 24
2) then in terminal run ./push_swap 100 to generate 100 numbers
3) to check with the checker, change back option_random = 0 on line 24
   and run
   ./push_swap $(cat example9.txt) | wc
   ./push_swap $(cat example9.txt) | ../checker_linux $(cat example9.txt)
*/
