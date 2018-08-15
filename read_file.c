/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:19:33 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 18:39:28 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

char	**ar_dup(char **new, char **old, int n, int d)
{
	int i;

	i = 0;
	new = (char **)ft_memalloc(sizeof(char *) * n);
	while (i < n / d)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	return (new);
}

void	vec_in(t_vec *vec)
{
	char	**temp;

	temp = NULL;
	if (vec->size == 0)
	{
		vec->cap = 2;
		vec->ar = (char **)ft_memalloc(sizeof(char *) * vec->cap);
	}
	if (vec->size == vec->cap)
	{
		temp = ar_dup(temp, vec->ar, vec->size, 1);
		free_ar(vec->ar, vec->cap);
		vec->cap *= 2;
		vec->ar = ar_dup(vec->ar, temp, vec->cap, 2);
		free_ar(temp, vec->size);
	}
}

void	read_file(t_lem *lem)
{
	char	*read;

	while (get_next_line(lem->fd, &read) > 0)
	{
		if (lem->vec->size == lem->vec->cap)
		{
			vec_in(lem->vec);
		}
		lem->vec->ar[lem->vec->size] = ft_strdup(read);
		lem->vec->size += 1;
		free(read);
	}
	free(read);
	lem->vec->ar[lem->vec->size] = NULL;
}

int		analyze(t_lem *lem)
{
	get_rooms(lem);
	get_ants(lem);
	find_begend(lem);
	ft_putstr_fd("start = ", 2);
	ft_putendl_fd(lem->start, 2);
	ft_putstr_fd("end = ", 2);
	ft_putendl_fd(lem->end, 2);
	return (0);
}

