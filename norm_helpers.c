/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 23:06:05 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/07 04:38:03 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void		mdf_help(uint32_t *f, uint32_t *g, t_ssl **mdf, int i)
{
	if (i < 16)
	{
		(*f) = ((*mdf)->b & (*mdf)->c) | ((~(*mdf)->b) & (*mdf)->d);
		(*g) = i;
	}
	else if (i < 32)
	{
		(*f) = ((*mdf)->d & (*mdf)->b) | ((~(*mdf)->d) & (*mdf)->c);
		(*g) = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		(*f) = (*mdf)->b ^ (*mdf)->c ^ (*mdf)->d;
		(*g) = (3 * i + 5) % 16;
	}
	else
	{
		(*f) = (*mdf)->c ^ ((*mdf)->b | (~(*mdf)->d));
		(*g) = (7 * i) % 16;
	}
}

void		sha256_init(t_ssl *ctx)
{
	ctx->datalen = 0;
	ctx->bitlen = 0;
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
}

void		final_h(t_ssl *ctx, unsigned char hash[])
{
	int i;

	i = 0;
	ctx->bitlen += ctx->datalen * 8;
	ctx->data[63] = ctx->bitlen;
	ctx->data[62] = ctx->bitlen >> 8;
	ctx->data[61] = ctx->bitlen >> 16;
	ctx->data[60] = ctx->bitlen >> 24;
	ctx->data[59] = ctx->bitlen >> 32;
	ctx->data[58] = ctx->bitlen >> 40;
	ctx->data[57] = ctx->bitlen >> 48;
	ctx->data[56] = ctx->bitlen >> 56;
	sha256_transform(ctx, ctx->data);
	while (i < 4)
	{
		hash[i] = (ctx->state[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = (ctx->state[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = (ctx->state[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (ctx->state[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (ctx->state[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (ctx->state[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (ctx->state[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (ctx->state[7] >> (24 - i * 8)) & 0x000000ff;
		i++;
	}
}

void		change_state(t_ssl *ctx, t_sha *s)
{
	ctx->state[0] += s->a;
	ctx->state[1] += s->b;
	ctx->state[2] += s->c;
	ctx->state[3] += s->d;
	ctx->state[4] += s->e;
	ctx->state[5] += s->f;
	ctx->state[6] += s->g;
	ctx->state[7] += s->h;
}

void		trans_help(t_ssl *ctx, t_sha *s, int i)
{
	s->f = ctx->state[5];
	s->g = ctx->state[6];
	s->h = ctx->state[7];
	i = 0;
	while (i < 64)
	{
		s->t1 = s->h + EP1(s->e) + CH(s->e, s->f, s->g) + g_sha[i] + s->m[i];
		s->t2 = EP0(s->a) + MAJ(s->a, s->b, s->c);
		s->h = s->g;
		s->g = s->f;
		s->f = s->e;
		s->e = s->d + s->t1;
		s->d = s->c;
		s->c = s->b;
		s->b = s->a;
		s->a = s->t1 + s->t2;
		i++;
	}
	change_state(ctx, s);
}
