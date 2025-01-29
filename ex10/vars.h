/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhug <mhug@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:44:43 by mhug              #+#    #+#             */
/*   Updated: 2024/09/26 17:58:18 by mhug             ###   ########.fr       */
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