/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:02 by mahug             #+#    #+#             */
/*   Updated: 2025/02/01 05:20:52 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void	check_result(t_vars vars)
{
	unsigned int	i;

	if (vars.ret_ft == vars.ret_libc
		&& strncmp(vars.dest_ft, vars.dest_libc, vars.n) == 0)
	{
		i = strlen(vars.src);
		while (i < vars.n)
		{
			if (vars.dest_ft[i] != vars.dest_libc[i])
			{
				printf("KO → %d \n", i);
				return ;
			}
			i++;
		}
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void	print_with_nulls(char *str, unsigned int n, char *name)
{
	unsigned int	i;

	printf("%s: ", name);
	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

void	allocate_memory(char **dest_ft, char **dest_libc, unsigned int n)
{
	*dest_ft = (char *)malloc(n + 1);
	*dest_libc = (char *)malloc(n + 1);
	if (!*dest_ft || !*dest_libc)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	memset(*dest_ft, 'X', n + 1);
	memset(*dest_libc, 'X', n + 1);
	(*dest_ft)[n] = '\0';
	(*dest_libc)[n] = '\0';
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 3)
	{
		printf("Usage: %s <string> <n>\n", argv[0]);
		return (0);
	}
	vars.src = argv[1];
	vars.n = atoi(argv[2]);
	allocate_memory(&vars.dest_ft, &vars.dest_libc, vars.n);
	vars.ret_ft = ft_strlcpy(vars.dest_ft, vars.src, vars.n);
	vars.ret_libc = strlcpy(vars.dest_libc, vars.src, vars.n);
	check_result(vars);
	print_with_nulls(vars.dest_ft, vars.n, "ft_strlcpy");
	print_with_nulls(vars.dest_libc, vars.n, "strlcpy");
	free(vars.dest_ft);
	free(vars.dest_libc);
	return (0);
}
