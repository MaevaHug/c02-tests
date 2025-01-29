/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <mahug@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:01:24 by mahug             #+#    #+#             */
/*   Updated: 2025/01/29 22:01:26 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(int argc, char **argv)
{
	char	*str;
	char	*str_to_upcase;

	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return (0);
	}
	str = argv[1];
	str_to_upcase = ft_strupcase(str);
	printf("%s\n", str_to_upcase);
	return (0);
}
