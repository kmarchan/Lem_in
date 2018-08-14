/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:19:33 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/14 09:05:14 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

char	*vec_in(t_vec *vec)
{
	char **temp;
	int i;

	i = 0;
	if (vec->size == 0)
	{
		vec->cap = 5;
		vec->ar = (char *)memalloc(sizeof(char) * vec->cap);
	}
	if (vec->size == vec->cap - 1)
	{
		vec->cap *= 2;
	}

}

void	read_file(char *ar[], t_lem *lem)
{
	char	*read;
	int		lin
	int		ret;

	lin = 0;
	while (get_next_line(lem->fd, &read) > 0)
	{
		if (lem->vec->size == lem->vec->cap)
		{
			lem->vec = vec_in(lem->vec)
		}
		lem->vec[lin] = ft_strdup(read);
		lin++;
		ft_strclr(read);
	}
}
