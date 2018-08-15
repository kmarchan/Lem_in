/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:21:38 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 09:11:45 by kmarchan         ###   ########.fr       */
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
	char				**ar;
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
	t_vec				*vec;
}						t_lem;

t_lem					*initialise(void);
void					free_all(t_lem *lem);
void					free_lst(t_lst *lst);
void					free_ar(char **ar, int n);
void					free_ar(char **ar, int n);
void					read_file(t_lem *lem);

#endif