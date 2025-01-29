/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <mahug@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:00:24 by mahug             #+#    #+#             */
/*   Updated: 2025/01/29 22:00:26 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	check_result(
		char *dest_ft, char *dest_libc, unsigned int n, unsigned int src_len)
{
	unsigned int	i;

	if (strncmp(dest_ft, dest_libc, n) == 0)
	{
		i = src_len;
		while (i < n)
		{
			if (dest_ft[i] != '\0' || dest_libc[i] != '\0')
			{
				printf("KO\n");
				return ;
			}
			i++;
		}
		printf("OK\n");
	}
	else
		printf("KO\n");
}

void	print_with_nulls(char *str, unsigned int n)
{
	unsigned int	i;

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
	char			*src;
	char			*dest_ft;
	char			*dest_libc;
	unsigned int	n;

	if (argc != 3)
	{
		printf("Usage: %s <string> <n>\n", argv[0]);
		return (0);
	}
	src = argv[1];
	n = atoi(argv[2]);
	allocate_memory(&dest_ft, &dest_libc, n);
	ft_strncpy(dest_ft, src, n);
	strncpy(dest_libc, src, n);
	check_result(dest_ft, dest_libc, n, strlen(src));
	print_with_nulls(dest_ft, n);
	print_with_nulls(dest_libc, n);
	free(dest_ft);
	free(dest_libc);
	return (0);
}
