/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_large_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:13:01 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/08 01:03:14 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int	sort_large(t_stack *stacka, t_stack *stackb);

int	multiple_choices_of_sort(t_sort_large *sort, char const *sort_name, \
						int opt_write, int *limit)
{
	int	res;
	int	want_every_sort_to_finish;

	want_every_sort_to_finish = 0;
	if (1 == want_every_sort_to_finish)
		*limit = -1;
	if (0 == ft_strncmp(sort_name, "updating sort", 50))
		res = sort_large_updating(sort->stacka, sort->stackb, \
					opt_write, *limit);
	else if (0 == ft_strncmp(sort_name, "raddix", 50))
		res = raddix_sort(sort->stacka, sort->stackb, opt_write, *limit);
	else if (0 == ft_strncmp(sort_name, "small big alter up", 50))
		res = sort_large_small_big_alter_up(sort->stacka, \
					sort->stackb, opt_write, *limit);
	else if (0 == ft_strncmp(sort_name, "small up sort", 50))
		res = sort_large_small_up(sort->stacka, sort->stackb, \
					opt_write, *limit);
	else if (0 == ft_strncmp(sort_name, "big up sort", 50))
		res = sort_large_small_up(sort->stacka, sort->stackb, \
					opt_write, *limit);
	else
		return (-2);
	return (res);
}

int	get_res_of_sort(t_sort_large *sort, char const *sort_name, \
					int opt_write, int *limit)
{
	t_stack			*stacka_copy;
	t_stack			*stackb_copy;
	t_sort_large	sort_copy;
	int				res;
	int				success;

	stacka_copy = copy_stack(sort->stacka);
	stackb_copy = copy_stack(sort->stackb);
	init_sort_large(&sort_copy, stacka_copy, stackb_copy);
	res = multiple_choices_of_sort(&sort_copy, sort_name, opt_write, limit);
	success = 0;
	if (0 == pert_cnt(stacka_copy))
		success = 1;
	free_two_stacks(stacka_copy, stackb_copy, 1);
	if (1 == 0)
	{
		if (1 == success)
			ft_printf("%-20s: [OK]  :  [%d]\n\n", sort_name, res);
		else
			ft_printf("%-20s: [xx]  :  [%d]\n\n", sort_name, res);
	}
	if (*limit < 0 || (1 == success && res < *limit))
		*limit = res;
	return (success);
}

//res = sort_large_updating(stacka, stackb);
int	sort_large(t_stack *stacka, t_stack *stackb)
{
	int				limit;
	t_sort_large	sort;

	init_sort_large(&sort, stacka, stackb);
	limit = -1;
	if (stacka->cnt <= 350)
		return (do_if_cnt_small(&sort, &limit));
	else if (stacka->cnt > 350)
		return (do_if_cnt_large(&sort, &limit));
	return (-1);
}

int	do_if_cnt_small(t_sort_large *sort, int *limit)
{
	int	res;

	get_res_of_sort(sort, "updating sort", 0, limit);
	res = *limit;
	get_res_of_sort(sort, "raddix", 0, limit);
	if (*limit > 0 && *limit < res)
	{
		res = *limit;
		get_res_of_sort(sort, "raddix", 1, limit);
		return (res);
	}
	else if (*limit > 0 && *limit >= res)
	{
		get_res_of_sort(sort, "updating sort", 1, limit);
		return (res);
	}
	return (-2);
}

int	do_if_cnt_large(t_sort_large *sort, int *limit)
{
	int	res;

	get_res_of_sort(sort, "raddix", 0, limit);
	res = *limit;
	get_res_of_sort(sort, "updating sort", 0, limit);
	if (*limit > 0 && *limit < res)
	{
		res = *limit;
		get_res_of_sort(sort, "updating sort", 0, limit);
		return (res);
	}
	else if (*limit > 0 && *limit >= res)
	{
		get_res_of_sort(sort, "raddix", 1, limit);
		return (res);
	}
	return (-1);
}

/*
other options for sorting algorithms:
on line ~40, choose between
a) sort_large_small_big_alter_up(&stacka, &stackb); 
	performance: 100->1.1K, 500->23K, 1K->89K
b) sort_large_small_up(&stacka, &stackb);
	performance: 100->1.7K, 500->34K, 1K->131K
c) sort_large_big_up(&stacka, &stackb);
	performance: 100->1.7K, 500->34K, 1K->135K
d) sort_large_updating(&stacka, &stackb);
	performance: 100->731, 500->10K, 1K->31K, 10K->1.2M
e) raddix_sort(&stacka, &stackb);

To generate random numbers, 
1) change option_random = 1 on line 24
2) then in terminal run ./push_swap 100 to generate 100 numbers
3) to check with the checker, change back option_random = 0 on line 24
   and run
   ./push_swap $(cat example9.txt) | wc
   ./push_swap $(cat example9.txt) | ../checker_linux $(cat example9.txt)
*/
