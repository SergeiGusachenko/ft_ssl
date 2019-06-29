/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergeygusachenko <sergeygusachenko@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:30:44 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/28 19:39:21 by sergeygusac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

static void		init_funcs(t_s_func *func)
{
	func[49] = &mdf_manage;
}

t_s_func		get_s_func(char *specifier)
{
	static t_s_func *funcs;

	if (!funcs)
	{
		funcs = malloc(sizeof(*funcs) * NUM_F);
		if (funcs)
			init_funcs(funcs);
	}
	return (funcs[get_hash(specifier)]);
}
