/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:49:12 by sgusache          #+#    #+#             */
/*   Updated: 2019/06/26 19:19:32 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../libft/libft.h"

# define NUM_SPEC 100

typedef struct		s_ssl
{
	int				f_p;
	int				f_q;
	int				f_r;
	int				f_s;
	int				no_f;
}					t_ssl;

typedef void		(*t_spec_func)(char **str);
int					get_hash(char *str);
t_spec_func			get_spec_func(char *specifier);
void				mdf_manage(char	**str);
void				shatfs_manage(char	**str);
void				error(char *str);
void				parse_flag(t_ssl **ssl, char **str);
void				mdf_res(t_ssl **mdf, char **str);

#endif
