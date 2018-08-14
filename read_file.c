/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:19:33 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/14 09:50:54 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

char	**ar_dup(char **new, char **old, int n)
{
	int i;

	i = 0;
	new = (char **)ft_memalloc(sizeof(char *) * n);
	while (i <= n)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
}

char	*vec_in(t_vec *vec)
{
	char **temp;
	// int i;

	if (vec->size == 0)
	{
		vec->cap = 5;
		vec->ar = (char **)ft_memalloc(sizeof(char *) * vec->cap);
	}
	if (vec->size == vec->cap - 1)
	{
		temp = ar_dup(temp, vec->ar, vec->cap);
		// temp = (char **)ft_memalloc(sizeof(char *) * vec->cap);
		// i = 0;
		// while (i <= vec->size)
		// {
		// 	temp[i] = ft_strdup(vec->ar[i]);
		// 	i++;
		// }
		free_ar(vec->ar);
		vec->cap *= 2;
		vec->ar = ar_dup(vec->ar, )
		temp = (char **)ft_memalloc(sizeof(char *) * vec->cap);
		i = 0;
		while (i <= vec->size)
		{
			temp[i] = ft_strdup(vec->ar[i]);
			i++;
		}
		free_ar(temp);
	}
}

void	read_file(char *ar[], t_lem *lem)
{
	char	*read;
	int		lin;
	int		ret;

	lin = 0;
	while (get_next_line(lem->fd, &read) > 0)
	{
		if (lem->vec->size == lem->vec->cap)
		{
			lem->vec = vec_in(lem->vec);
		}
		lem->vec->ar[lin] = ft_strdup(read);
		lin++;
		ft_strclr(read);
	}
}
