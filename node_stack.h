/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:32:58 by Ektin Op Urims    #+#    #+#             */
/*   Updated: 2023/08/08 01:03:37 by Ektin Op Urims   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_STACK_H
# define NODE_STACK_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				ordinit;
	int				rel_val;
	int				glob_rel_val;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*n;
	struct s_node	*p;
}	t_node;

typedef struct s_pair
{
	t_node	*beg;
	t_node	*end;
}	t_pair;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	t_node	*f;
	t_node	*l;
	int		cnt;
}	t_stack;

typedef struct s_four_numbers
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_four_numbers;

typedef struct s_sort_large
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		pert_cnt_a;
	int		min_a;
	int		max_a;
	int		tot_oper_cnt;
}	t_sort_large;

// node.c
void	set_node(t_node *node, int num, int ord);
void	free_node(t_node *node);

// stack.c
void	init_stack(t_stack *stack);
void	add_node_to_stack(t_stack *stack, int newval);
void	delete_first_node_from_stack(t_stack *stack);
void	free_stack(t_stack *stack, int opt_free);
t_stack	*copy_stack(t_stack const *stack);

// stack_aux.c
void	init_two_stacks(t_stack *stacka, t_stack *stackb);
int		free_two_stacks(t_stack *stacka, t_stack *stackb, int opt_free);
void	display_stack(t_stack *stack);
void	display_stack_cost(t_stack *stack);

// stack_operations.c
void	swap(t_stack *stack);
void	push_to_first_from_second(t_stack *stacka, t_stack *stackb);
void	rotate(t_stack *stack);
void	revrotate(t_stack *stack);

// stack_sasbss.c
void	sa(t_stack *stacka, t_stack *stackb, int opt_write);
void	sb(t_stack *stacka, t_stack *stackb, int opt_write);
void	ss(t_stack *stacka, t_stack *stackb, int opt_write);

// stack_papb.c
void	pa(t_stack *stacka, t_stack *stackb, int opt_write);
void	pb(t_stack *stacka, t_stack *stackb, int opt_write);

// stack_rarbrr.c
void	ra(t_stack *stacka, t_stack *stackb, int opt_write);
void	rb(t_stack *stacka, t_stack *stackb, int opt_write);
void	rr(t_stack *stacka, t_stack *stackb, int opt_write);

// stack_rrarrbrrr.c
void	rra(t_stack *stacka, t_stack *stackb, int opt_write);
void	rrb(t_stack *stacka, t_stack *stackb, int opt_write);
void	rrr(t_stack *stacka, t_stack *stackb, int opt_write);

// reading_input.c
void	read_input(int args, char *argv[], t_stack *stack, int *err);

// generating_random_input.c
int		get_params_cnt_from_argv(int argc, char **argv, int *cnt);	
int		get_params_optsave_verbose_from_argv(int argc, char **argv, \
			int *optsave, int *verbose);	
void	generate_random_input(int argc, char **argv, \
			t_stack *stack, char *file_name);
int		open_file_set_fd(char *file_name, int *fd);
void	write_num_to_file(int fd, int num, int verbose);

// print_err.c
int		print_error_and_free_stack(t_stack *stack, int option);

// sort_small.c
int		sort_small(t_stack *stacka, t_stack *stackb, int opt_write);
int		sort2(t_stack *stacka, t_stack *stackb, int opt_write);
int		sort3(t_stack *stacka, t_stack *stackb, int opt_write);
int		sort3_12(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort3_3(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);

// sort_four.c
int		min_in_stack(t_stack *stack);
int		sort4(t_stack *stacka, t_stack *stackb, int opt_write);
int		sort4_1_123(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_1_4(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
// sort_four_2_aux.c
int		sort4_2(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_2_1(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_2_3(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_2_4(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
// sort_four_3_aux.c
int		sort4_3(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_3_1(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_3_2(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_3_4(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
// sort_four_4_aux.c
int		sort4_4(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_4_1(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_4_2(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);
int		sort4_4_3(t_stack *stacka, t_stack *stackb, \
				t_four_numbers const *f, int opt_write);

// normal_sort_operations.c
void	fill_n_p(t_stack *stack, int option);
void	swap_nodes_n_p(t_node *node1, t_node *node2, t_stack *stack);
t_node	*normal_sort_subroutine(t_pair *pair, t_stack *stack, int val, int opt);
void	normalsort(t_node *left, t_node *right, t_stack *stack, int *error);
void	display_stack_n_p(t_stack *stack);

// normal_sort_operations_aux.c
void	swap_integers(int *a, int *b);
void	swap_pointers(t_node **a, t_node **b);
void	settle_pointers(t_node *a, t_node *b);

// perturbations_count.c
int		pert_cnt(t_stack *stack);
void	recompute_pert_cnt(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt);
void	recompute_pert_cnt_sa(t_stack *stacka, t_stack *stackb, int *pert_cnt);
void	recompute_pert_cnt_pb_pa(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt);
void	recompute_pert_cnt_ra_rra(t_stack *stacka, t_stack *stackb, \
				char const *oper, int *pert_cnt);

// small_or_big_up_sort.c
int		initial_operations_with_stack(t_stack *stack);
void	init_sort_large(t_sort_large *sort_large, \
			t_stack *stacka, t_stack *stackb);
int		sort_large_small_up(t_stack *stacka, t_stack *stackb, \
					int opt_write, int limit);
int		sort_large_big_up(t_stack *stacka, t_stack *stackb, \
					int opt_write, int limit);
int		get_pos_of_elem_in_stack(t_stack *stack, int rel_val);

// small_or_big_up_sort_aux.c
void	do_pb(t_sort_large *sort_large, int option, int opt_write);
void	do_pa(t_sort_large *sort_large, int option, int opt_write);
void	do_ra(t_sort_large *sort_large, int opt_write);
void	do_rra(t_sort_large *sort_large, int opt_write);
void	move_pos_up(t_sort_large *sort_large, int pos, int opt_write);

// small_and_big_alternate_sort.c
int		sort_large_small_big_alter_up(t_stack *stacka, \
			t_stack *stackb, int opt_write, int limit);
void	set_costs_and_move(t_sort_large *sort_large, int *cost1, int *cost2, \
				int opt_write);
void	moving_everything_from_b_to_a(t_sort_large *sort_large, int opt_write);
int		is_lim_ok(t_sort_large const *sort_large, int limit);

// updating_sort.c
int		sort_large_updating(t_stack *stacka, t_stack *stackb, \
					int opt_write, int limit);
void	set_glob_rel_val(t_stack *stack, int option);
void	set_costs_updating(t_stack *stacka);
int		min_cost_index_in_stack(t_stack *stack, int *pos);

// updating_sort_aux1.c
void	do_sa(t_sort_large *sort_large, int opt_write);
void	do_ra_mult_times(t_sort_large *sort_largei, int num, int opt_write);
void	do_rra_mult_times(t_sort_large *sort_largei, int num, int opt_write);

// updating_sort_aux2.c
int		find_proper_pos_for_elem_in_stack(t_stack *stack, int num);
void	moving_everything_from_b_to_a_updating(t_sort_large *sort_large, \
							int opt_write);
void	do_if_first_half(t_sort_large *sort_large, int pos, int opt_write);
void	do_if_second_half(t_sort_large *sort_large, int pos, int stackacnt, \
							int opt_write);

// raddix_sort.c
int		raddix_sort(t_stack *stacka, t_stack *stackb, int opt_write, int limit);
int		get_tot_oper_cnt(t_sort_large *sort_large);

// combined_large_sort.c
int		sort_large(t_stack *stacka, t_stack *stackb);
int		multiple_choices_of_sort(t_sort_large *sort, \
			char const *sort_name, int opt_write, int *limit);
int		get_res_of_sort(t_sort_large *sort, \
			char const *sort_name, int opt_write, int *limit);
int		do_if_cnt_small(t_sort_large *sort, int *limit);
int		do_if_cnt_large(t_sort_large *sort, int *limit);

#endif
