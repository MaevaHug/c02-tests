/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:01:15 by mahug             #+#    #+#             */
/*   Updated: 2025/02/07 06:21:58 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		printf("Examples:\n");
		printf("  %s \"Hello\"             # normal string\n", argv[0]);
		printf("  %s $'Hello\\n'          # with newline\n", argv[0]);
		printf("  %s $'Hello\\t'          # with tab\n", argv[0]);
		printf("  %s $'\\x00'             # null char\n", argv[0]);
		printf("  %s $'Hello\\x7FWorld'   # with DEL char\n", argv[0]);
		return (0);
	}
	printf("%d\n", ft_str_is_printable(argv[1]));
	return (0);
}
