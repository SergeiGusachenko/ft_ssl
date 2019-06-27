/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:30:44 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/26 20:00:11 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

static void		init_funcs(t_spec_func *func)
{
	func[49] = &mdf_manage;
}

t_spec_func		get_spec_func(char *specifier)
{
	static t_spec_func *funcs;

	if (!funcs)
	{
		funcs = malloc(sizeof(*funcs) * NUM_SPEC);
		if (funcs)
			init_funcs(funcs);
	}
	return (funcs[get_hash(specifier)]);
}
