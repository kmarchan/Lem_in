/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:19:33 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/20 11:31:40 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

void	read_file(t_lem *lem)
{
	int		c;
	char	*read;

	c = 0;
	while (get_next_line(lem->fd, &read) > 0)
	{
		c = 1;
		if (lem->vec->size == lem->vec->cap)
		{
			vec_in(lem->vec);
		}
		lem->vec->ar[lem->vec->size] = ft_strdup(read);
		lem->vec->size += 1;
		free(read);
	}
	if (c == 0)
	{
		ft_putendl_fd(RED "Invalid File" RESET, 2);
		exit(1);
	}
	free(read);
	lem->vec->ar[lem->vec->size] = NULL;
}

int		analyze(t_lem *lem)
{
	ft_putendl_fd("A", 2);
	get_rooms(lem);
	ft_putendl_fd("N", 2);
	get_ants(lem);
	ft_putendl_fd("L", 2);
	find_begend(lem);
	ft_putendl_fd("Y", 2);
	get_links(lem);
	ft_putendl_fd("Z", 2);
	get_path(lem);
	ft_putendl_fd("E", 2);
	return (0);
}

