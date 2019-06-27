/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:27:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/26 20:00:17 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	mdf_manage(char	**str)
{
	t_ssl *mdf;

	mdf = ft_memalloc(sizeof(t_ssl));
	parse_flag(&mdf, str);
	//mdf_res(&mdf, str);
}
