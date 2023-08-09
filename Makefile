# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 17:55:40 by Ektin Op Urims          #+#    #+#              #
#    Updated: 2023/08/09 16:46:06 by Ektin Op Urims         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = node.c \
		stack.c \
		stack_aux.c \
		stack_operations.c \
		stack_sasbss.c \
		stack_papb.c \
		stack_rarbrr.c \
		stack_rrarrbrrr.c \
		reading_input.c \
		generating_random_input.c \
		print_err.c \
		sort_small.c \
		sort_four.c \
		sort_four_2_aux.c \
		sort_four_3_aux.c \
		sort_four_4_aux.c \
		normal_sort_operations.c \
		normal_sort_operations_aux.c \
		perturbations_count.c \
		small_or_big_up_sort.c \
		small_or_big_up_sort_aux.c \
		small_and_big_alternate_sort.c \
		updating_sort.c \
		updating_sort_aux1.c \
		updating_sort_aux2.c \
		raddix_sort.c \
		combined_large_sort.c \

SRC_PUSH_SWAP =	$(SRC_COMMON) push_swap.c
SRC_CHECKER = $(SRC_COMMON) checker.c

HEADER_PUSH_SWAP = node_stack.h
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

NAME = push_swap
NAME_BONUS = checker

LIBFTDIR = libft/
NAMELIBFT = $(addprefix $(LIBFTDIR), libft.a)
SHORTNAMELIBFT = -lft

CC = cc
CFLAGS += -Wall -Wextra -Wpedantic -Werror
NORM = /bin/norminette

all: $(NAME)

bonus: $(NAME_BONUS)

NORM:
	@if [ "$(wildcard $(NORM))" != "" ]; then \
		$(NORM) $(SRC_PUSH_SWAP) $(HEADER_PUSH_SWAP);\
	fi

NORM_BONUS:
	@if [ "$(wildcard $(NORM))" != "" ]; then \
		$(NORM) $(SRC_CHECKER) $(HEADER_PUSH_SWAP);\
	fi

$(NAME):	$(NAMELIBFT) $(OBJ_PUSH_SWAP)
	$(CC) -o $(NAME) $(OBJ_PUSH_SWAP) -I$(LIBFTDIR) -L$(LIBFTDIR) -lft
	make NORM

$(NAME_BONUS):	$(NAMELIBFT) $(OBJ_CHECKER)
	$(CC) -o $(NAME_BONUS) $(OBJ_CHECKER) -I$(LIBFTDIR) -L$(LIBFTDIR) -lft
	make NORM_BONUS

%.o:	%.c
	echo "Salut"
	$(CC) -o $@ -c $< $(CFLAGS) -I$(LIBFTDIR)

$(NAMELIBFT):
	make -C $(LIBFTDIR)

clean:
	make -C $(LIBFTDIR) clean
	rm -f $(wildcard *.o) $(wildcard *.h.gch) $(wildcard .*.swp)

fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(wildcard *.a) $(wildcard *.out) $(wildcard *.so) $(NAME) $(NAME_BONUS)

re:
	make -C $(LIBFTDIR) fclean
	make fclean
	make

.PHONY: clean fclean
