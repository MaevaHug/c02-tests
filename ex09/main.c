/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <mahug@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:01:42 by mahug             #+#    #+#             */
/*   Updated: 2025/01/29 22:01:45 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(int argc, char **argv)
{
	char	*str;
	char	*str_to_capitalize;

	if (argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return (0);
	}
	str = argv[1];
	str_to_capitalize = ft_strcapitalize(str);
	printf("%s\n", str_to_capitalize);
	return (0);
}
