/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:00:33 by mahug             #+#    #+#             */
/*   Updated: 2025/02/01 05:19:02 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return (0);
	}
	printf("%d\n", ft_str_is_alpha(argv[1]));
	return (0);
}
