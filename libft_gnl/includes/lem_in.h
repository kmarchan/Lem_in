#ifndef	LEM_IN_H
# define LEM_IN_H
# define ERROR ft_putendl_fd("Error", 2);
# include "libft.h"
# include "get_next_line.h"

typedef struct			s_lst
{
	char				*data;
	struct	s_lst		*next;
	char 				**link;
}						t_lst;

typedef struct			s_lem
{
	int					fd;
	int					ant;
	t_lst				rms;
}						t_lem;

# endif