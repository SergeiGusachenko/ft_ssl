/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shatfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 20:04:07 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/07 04:54:12 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void		shatfs_manage(char **str)
{
	t_ssl			ctx;
	unsigned char	*text;

	text = NULL;
	ctx.algo = 0;
	parse_sha(text, &ctx, str);
}

size_t		byte_len(unsigned char buf[])
{
	int i;

	i = 0;
	while (buf[i])
		i++;
	return (i);
}

void		sha256_transform(t_ssl *ctx, const unsigned char data[])
{
	t_sha	s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < 16)
	{
		s.m[i] = (data[j] << 24) | (data[j + 1] << 16)
		| (data[j + 2] << 8) | (data[j + 3]);
		j += 4;
		i++;
	}
	while (i < 64)
	{
		s.m[i] = SIG1(s.m[i - 2]) + s.m[i - 7]
		+ SIG0(s.m[i - 15]) + s.m[i - 16];
		i++;
	}
	s.a = ctx->state[0];
	s.b = ctx->state[1];
	s.c = ctx->state[2];
	s.d = ctx->state[3];
	s.e = ctx->state[4];
	trans_help(ctx, &s, i);
}

void		sha256_update(t_ssl *ctx, const unsigned char data[], size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len)
	{
		ctx->data[ctx->datalen] = data[i];
		ctx->datalen++;
		if (ctx->datalen == 64)
		{
			sha256_transform(ctx, ctx->data);
			ctx->bitlen += 512;
			ctx->datalen = 0;
		}
		i++;
	}
}

void		sha256_final(t_ssl *ctx, unsigned char hash[])
{
	unsigned int i;

	i = ctx->datalen;
	if (ctx->datalen < 56)
	{
		ctx->data[i++] = 0x80;
		while (i < 56)
			ctx->data[i++] = 0x00;
	}
	else
	{
		ctx->data[i++] = 0x80;
		while (i < 64)
			ctx->data[i++] = 0x00;
		sha256_transform(ctx, ctx->data);
		memset(ctx->data, 0, 56);
	}
	final_h(ctx, hash);
}
