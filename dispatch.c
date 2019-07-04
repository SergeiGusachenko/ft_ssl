/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:30:44 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/03 22:36:17 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

static void		init_funcs(t_s_func *func)
{
	func[49] = &mdf_manage;
	func[13] = &shatfs_manage;
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
