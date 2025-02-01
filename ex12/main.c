/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:29 by mahug             #+#    #+#             */
/*   Updated: 2025/02/01 05:21:25 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_print_memory(void *addr, unsigned int size);

// size = 92;
// str = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire "
// "avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
int	main(int argc, char **argv)
{
	char			*str;
	unsigned int	size;

	if (argc != 3)
	{
		printf("Usage: %s <string> <size>\n", argv[0]);
		return (0);
	}
	str = argv[1];
	size = (unsigned int)atoi(argv[2]);
	ft_print_memory(str, size);
	return (0);
}
