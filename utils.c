/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:26:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/07/07 04:54:42 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void		error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int			check_f(t_ssl **ssl, char *str, char **arg, int position)
{
	int		i;
	int		f;

	i = 1;
	f = 1;
	(*ssl)->pos = position;
	while (str[i] != '\0')
	{
		if (str[i] == 'p' && (*ssl)->f_s == 0)
			m_p(ssl, str);
		else if (str[i] == 'q' && (*ssl)->f_s == 0)
			return (*ssl)->f_q = i;
		else if (str[i] == 'r' && (*ssl)->f_s == 0)
			(*ssl)->f_r = i;
		else if (str[i] == 's')
		{
			m_s(ssl, str, arg, position);
			(*ssl)->f_s++;
		}
		else if ((*ssl)->f_s == 0)
			f--;
		i++;
	}
	return (f);
}

void		parse_flag(t_ssl **ssl, char **str)
{
	int				i;
	unsigned char	*c;

	c = NULL;
	i = 2;
	while (str[i])
	{
		init_h(ssl);
		if (str[i][0] == '-')
		{
			if (((*ssl)->max_f = check_f(ssl, str[i], str, i)))
				i = (*ssl)->pos;
			else
				error("invalid option\n");
		}
		else if (str[i][0] != '-')
		{
			c = file_r(ssl, str[i]);
			md5(c, ssl);
			print_msg(*ssl);
			if ((*ssl)->f_r > 0)
				ft_printf(" %s\n", str[i]);
		}
		i++;
	}
}

void		ft_sha256print_hash(unsigned char hash[])
{
	int idx;

	idx = 0;
	while (idx < 32)
	{
		ft_printf("%02x", hash[idx]);
		idx++;
	}
	ft_printf("\n");
}

void		parse_sha(unsigned char *text, t_ssl *ctx, char **str)
{
	int				i;
	unsigned char	buf[SHA256_BLOCK_SIZE];

	i = 2;
	while (str[i])
	{
		sha256_init(ctx);
		if (str[i][0] == '-')
		{
			if ((ctx->max_f = check_f(&ctx, str[i], str, i)))
				i = (ctx)->pos;
			else
				error("invalid option\n");
		}
		else if (str[i][0] != '-')
		{
			text = file_r(&ctx, str[i]);
			sha256_update(ctx, text, byte_len(text));
			sha256_final(ctx, buf);
			ft_sha256print_hash(buf);
		}
		i++;
	}
}
