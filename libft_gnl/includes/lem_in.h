/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:21:38 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 09:46:44 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ERROR ft_putendl_fd("Error", 2);
# include "libft.h"
# include "get_next_line.h"

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct			s_vec
{
	int					size;
	int					cap;
	char				**ar;
}						t_vec;

typedef struct			s_lst
{
	int					lnum;
	char				*name;
	struct s_lst		*next;
	t_vec				*lnk;
}						t_lst;

typedef struct			s_lem
{
	int					fd;
	int					ant;
	char				*start;
	char				*end;
	t_lst				*lst;
	t_vec				*vec;
}						t_lem;

t_lem					*initialise(void);
void					vec_in(t_vec *vec);
char					**ar_dup(char **new, char **old, int n, int d);

void					free_all(t_lem *lem);
void					free_lst(t_lst *lst);
void					free_ar(char **ar, int n);
void					free_ar(char **ar, int n);
void					read_file(t_lem *lem);
void					get_ants(t_lem *lem);
void					find_begend(t_lem *lem);
char					*set_point(char *lin);
int						analyze(t_lem *lem);
int						ft_lstlen(t_lst *lst);
t_lst					*ft_lstnew(void);
void					get_rooms(t_lem *lem);
void					del_extra(t_lst *lst);
void					get_links(t_lem *lem);

#endif
