/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:50:41 by sergeygusac       #+#    #+#             */
/*   Updated: 2019/07/06 16:57:06 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void				init_f(t_ssl **mdf)
{
	(*mdf)->algo = 1;
	(*mdf)->f_p = 0;
	(*mdf)->f_s = 0;
	(*mdf)->f_r = 0;
	(*mdf)->f_q = 0;
	(*mdf)->no_f = 0;
	(*mdf)->msg_len = 0;
	(*mdf)->h0 = 0x67452301;
	(*mdf)->h1 = 0xefcdab89;
	(*mdf)->h2 = 0x98badcfe;
	(*mdf)->h3 = 0x10325476;
	(*mdf)->a = 0x67452301;
	(*mdf)->b = 0xefcdab89;
	(*mdf)->c = 0x98badcfe;
	(*mdf)->d = 0x10325476;
}

void				init_h(t_ssl **mdf)
{
	(*mdf)->msg_len = 0;
	(*mdf)->h0 = 0x67452301;
	(*mdf)->h1 = 0xefcdab89;
	(*mdf)->h2 = 0x98badcfe;
	(*mdf)->h3 = 0x10325476;
	(*mdf)->a = 0x67452301;
	(*mdf)->b = 0xefcdab89;
	(*mdf)->c = 0x98badcfe;
	(*mdf)->d = 0x10325476;
}

void				error_f(char *str)
{
	ft_printf("%s: No such file or directory", str);
	error("");
}

char				*read_file(t_ssl **ssl, char *str)
{
	int		fd;
	int		num_r;
	char	buff[BUFFSIZE];
	char	*temp;

	(*ssl)->f_p = 0;
	num_r = 0;
	fd = 0;
	fd = open(str, O_RDONLY);
	temp = ft_strnew(1);
	if (fd < 0)
		error_f(str);
	(*ssl)->file_n = str;
	while ((num_r = read(fd, &buff, BUFFSIZE)) > 0)
	{
		buff[num_r] = '\0';
		temp = ft_update(temp, ft_strjoin(temp, buff));
		(*ssl)->msg_len += num_r;
	}
	if ((*ssl)->f_r == 0 && (*ssl)->f_q == 0 && (*ssl)->algo == 1)
		ft_printf("MD5 (\"%s\") = ", str);
	if ((*ssl)->f_r == 0 && (*ssl)->f_q == 0 && (*ssl)->algo == 0)
		ft_printf("SHA256 (\"%s\") = ", str);
	return (temp);
}

unsigned char		*file_r(t_ssl **ssl, char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = str;
	while (s[i])
	{
		if (s[i] != '-')
			return ((unsigned char*)read_file(ssl, s));
		i++;
	}
	return (NULL);
}
