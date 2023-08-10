/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:26:57 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 15:49:16 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"

int		read_and_apply_instructions(t_stack *stacka, t_stack *stackb);
void	treating_instruction(t_stack *stacka, t_stack *stackb, \
				char *curr_instruction, int *err);

int	main(int argc, char *argv[])
{
	int		err;
	t_stack	stacka;
	t_stack	stackb;

	if (1 == argc)
		return (0);
	init_two_stacks(&stacka, &stackb);
	read_input(argc, argv, &stacka, &err);
	if (1 == err || (2 == argc && 0 == stacka.cnt))
		return (print_error_and_free_stack(&stacka, 0));
	if (1 == initial_operations_with_stack(&stacka))
		return (1);
	if (1 == read_and_apply_instructions(&stacka, &stackb))
		return (print_error_and_free_stack(&stacka, 0));
	if (0 == stackb.cnt && 0 == pert_cnt(&stacka))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_two_stacks(&stacka, &stackb, 0);
	return (0);
}

int	read_and_apply_instructions(t_stack *stacka, t_stack *stackb)
{
	char	*curr_instruction;
	int		err;

	curr_instruction = (char *)&stacka;
	err = 0;
	while (NULL != curr_instruction && 0 == err)
	{
		curr_instruction = get_next_line(0);
		if (NULL != curr_instruction)
			treating_instruction(stacka, stackb, curr_instruction, &err);
		free(curr_instruction);
	}
	return (err);
}

void	treating_instruction(t_stack *stacka, t_stack *stackb, \
				char *curr_instruction, int *err)
{
	if (0 == ft_strncmp(curr_instruction, "sa\n", 10))
		sa(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "sb\n", 10))
		sb(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "ss\n", 10))
		ss(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "pa\n", 10))
		pa(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "pb\n", 10))
		pb(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "ra\n", 10))
		ra(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "rb\n", 10))
		rb(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "rr\n", 10))
		rr(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "rra\n", 10))
		rra(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "rrb\n", 10))
		rrb(stacka, stackb, 0);
	else if (0 == ft_strncmp(curr_instruction, "rrr\n", 10))
		rrr(stacka, stackb, 0);
	else
		*err = 1;
}
