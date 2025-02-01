/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahug <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:21:04 by mahug             #+#    #+#             */
/*   Updated: 2025/02/01 05:21:09 by mahug            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>

typedef struct s_vars	t_vars;

struct s_vars
{
	char			*src;
	char			*dest_ft;
	char			*dest_libc;
	unsigned int	n;
	unsigned int	ret_ft;
	unsigned int	ret_libc;
};

#endif