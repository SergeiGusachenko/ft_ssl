/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:27:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/07 02:16:41 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	print_msg(t_ssl *mdf)
{
	uint8_t *p;

	p = (uint8_t *)&mdf->h0;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&mdf->h1;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&mdf->h2;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&mdf->h3;
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	if (mdf->f_r == 0)
		ft_printf("\n");
}

void	mdf_main(t_ssl **mdf, uint32_t *w)
{
	int			i;
	uint32_t	g;
	uint32_t	f;
	uint32_t	temp;

	i = 0;
	while (i < 64)
	{
		mdf_help(&f, &g, mdf, i);
		temp = (*mdf)->d;
		(*mdf)->d = (*mdf)->c;
		(*mdf)->c = (*mdf)->b;
		(*mdf)->b = (*mdf)->b +
		LEFTROTATE(((*mdf)->a + f + g_k[i] + w[g]), g_r[i]);
		(*mdf)->a = temp;
		i++;
	}
}

void	mdf_h(uint32_t *w, t_ssl **mdf, int offset, uint8_t *msg)
{
	w = (uint32_t *)(msg + offset);
	mdf_main(mdf, w);
	(*mdf)->h0 += (*mdf)->a;
	(*mdf)->h1 += (*mdf)->b;
	(*mdf)->h2 += (*mdf)->c;
	(*mdf)->h3 += (*mdf)->d;
}

void	md5(unsigned char *initial_msg, t_ssl **mdf)
{
	uint8_t		*msg;
	uint32_t	*w;
	int			offset;
	int			new_len;
	uint32_t	bits_len;

	msg = NULL;
	offset = 0;
	new_len = (*mdf)->msg_len * 8 + 1;
	w = NULL;
	while (new_len % 512 != 448)
		new_len++;
	new_len /= 8;
	msg = ft_memalloc(new_len + 64);
	ft_memcpy(msg, initial_msg, (*mdf)->msg_len);
	msg[(*mdf)->msg_len] = 128;
	bits_len = 8 * (*mdf)->msg_len;
	ft_memcpy(msg + new_len, &bits_len, 4);
	while (offset < new_len)
	{
		mdf_h(w, mdf, offset, msg);
		offset += (512 / 8);
	}
	free(msg);
}

void	mdf_manage(char **str)
{
	t_ssl *mdf;

	mdf = ft_memalloc(sizeof(t_ssl));
	init_f(&mdf);
	parse_flag(&mdf, str);
	free(mdf);
}
