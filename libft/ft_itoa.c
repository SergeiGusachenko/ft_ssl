/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:37:13 by sgusache          #+#    #+#             */
/*   Updated: 2018/12/11 11:13:52 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		size;

	size = nb_size(n);
	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
		size++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str = fill_str(str, n, i);
	str_rev(str, i);
	return (str);
}
