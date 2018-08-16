/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:13:22 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 11:45:03 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

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
