/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:21:38 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/14 08:50:18 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ERROR ft_putendl_fd("Error", 2);
# include "libft.h"
# include "get_next_line.h"

typedef struct			s_vec
{
	int					size;
	int					cap;
	char				*ar;
}						t_vec;

typedef struct			s_lst
{
	char				*data;
	struct s_lst		*next;
	char				**link;
}						t_lst;

typedef struct			s_lem
{
	int					fd;
	int					ant;
	t_lst				lst;
	t_vec				**vec;
}						t_lem;

#endif