/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generating_random_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ektin Op Urims <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:27:35 by Ektin Op Urims          #+#    #+#             */
/*   Updated: 2023/08/06 13:44:15 by Ektin Op Urims         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_stack.h"
#include <time.h>
#include <fcntl.h>

int	get_param_cnt_from_argv(int argc, char **argv, int *cnt)
{
	int	err;

	if (argc < 2)
	{
		ft_printf("Wrong call in the mode of random numer generation\n\n");
		return (-2);
	}
	err = 0;
	*cnt = ft_atoi_err(argv[1], &err);
	if (1 == err)
	{
		ft_printf("Error in reading input in the random generation mode. ");
		ft_printf("Setting to 10\n\n");
		*cnt = 10;
	}
	return (0);
}

int	get_params_optsave_verbose_from_argv(int argc, char **argv, \
					int *optsave, int *verbose)
{
	int	err;
	int	res;

	*optsave = 1;
	*verbose = 0;
	if (argc >= 3)
	{
		err = 0;
		res = ft_atoi_err(argv[2], &err);
		if (0 == err && 0 == res)
			*optsave = 0;
	}
	if (argc >= 4)
	{
		err = 0;
		res = ft_atoi_err(argv[3], &err);
		if (0 == err && 1 == res)
			*verbose = 1;
	}
	return (0);
}

// in order not to more than 5 arguments, misusing argc
void	generate_random_input(int argc, char **argv, \
			t_stack *stack, char *file_name)
{
	int	fd;
	int	num;
	int	cnt;
	int	option_save;
	int	verbose;

	get_param_cnt_from_argv(argc, argv, &cnt);
	get_params_optsave_verbose_from_argv(argc, argv, &option_save, &verbose);
	if (1 == verbose)
		ft_printf("file_name is [%s]\n\n", file_name);
	open_file_set_fd(file_name, &fd);
	srand(time(NULL));
	argc = 0;
	if (1 == verbose || fd < 0)
		ft_printf("fd is %d\n\n", fd);
	while (argc++ < cnt)
	{
		num = rand();
		add_node_to_stack(stack, num);
		if (1 == option_save)
			write_num_to_file(fd, num, verbose);
	}
	close(fd);
}

int	open_file_set_fd(char *file_name, int *fd)
{
	*fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	close(*fd);
	*fd = open(file_name, O_WRONLY);
	return (*fd);
}

void	write_num_to_file(int fd, int num, int verbose)
{
	char	*str;
	int		res;

	str = ft_itoa(num);
	if (NULL != str)
	{
		if (1 == verbose)
			ft_printf("trying to write [%s] to fd=%d\n\n", str, fd);
		res = write(fd, str, ft_strlen(str));
		if (1 == verbose)
			ft_printf("[[%d]]\n\n", res);
		write(fd, " ", 1);
	}
	free(str);
}
