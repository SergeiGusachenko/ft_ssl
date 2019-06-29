/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergeygusachenko <sergeygusachenko@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:50:41 by sergeygusac       #+#    #+#             */
/*   Updated: 2019/06/28 20:21:01 by sergeygusac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"
#include <fcntl.h>

char	*read_file(t_ssl **ssl, char *str)
{
	int 	fd;
	int 	num_r;
	char	buff[BUFFSIZE];
	char	*temp;

	(*ssl)->f_p = 0;
	num_r = 0;
	fd = 0;
	fd = open(str, O_RDONLY);
	temp = NULL;
	if(fd < 0)
	{
		ft_printf("%s :No such file or directory\n",str);
		error("");
	}
	while ((num_r = read(fd, &buff, BUFFSIZE) > 0))
	{
		buff[num_r] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	return (temp);
}

unsigned char		*file_r(t_ssl **ssl, char **str)
{
	char *s;
	int i;

	i = 0;
	s = str[2];
	while(s[i])
	{
		if(s[i] != '-')
			return ((unsigned char*)read_file(ssl, s));
	}
	return (NULL);
}
