# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ektin Op Urims <marvin@42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 10:11:05 by Ektin Op Urims    #+#    #+#              #
#    Updated: 2023/08/06 11:27:16 by Ektin Op Urims   ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

To generate 100 random numbers,
1) set option_random = 1; in push_swap.c, line 22
2) run make, then ./push_swap 100
To check your results via checker,
3) set option_random = 0; in push_swap.c, line 22
3) run 
3a) ARG=$(cat example5.txt)
3b) ./push_swap $ARG
3c) ./push_swap $ARG | wc
3d) ./push_swap $ARG | ../checker_linux	$ARG

To change between different sorting algorithms, 
on line 38, choose between
1) sort_large_small_up(&stacka, &stackb);
2) sort_large_big_up(&stacka, &stackb);
3) sort_large_small_big_alter_up(&stacka, &stackb);
