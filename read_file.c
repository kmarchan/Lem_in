/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:19:33 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 13:06:22 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "get_next_line.h"

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
	get_links(lem);
	ft_putstr_fd(CYN "ants = " RESET, 2);
	ft_putnbr_fd(lem->ant, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(CYN "start = " RESET, 2);
	ft_putendl_fd(lem->start, 2);
	ft_putstr_fd(CYN "end = " RESET, 2);
	ft_putendl_fd(lem->end, 2);
	ft_putendl_fd(CYN "ROOMS:" RESET, 2);
	int i;
	while (lem->lst != NULL)
	{
		i = 0;
		ft_putendl_fd(lem->lst->name, 2);
		while (i < lem->lst->lnk->size)
		{
			ft_putstr_fd(lem->lst->lnk->ar[i], 2);
			ft_putchar_fd(' ', 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		lem->lst = lem->lst->next;
	}
	ft_putendl_fd(lem->end, 2);
	return (0);
}

