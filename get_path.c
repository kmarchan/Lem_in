/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:11:42 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/17 12:35:59 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	find_first_step(t_lem *lem)
{
	t_lst	*tmp;
	int		i;

	tmp = lem->lst;
	while (tmp)
	{
		i = 0;
		while (i < tmp->lnk->size)
		{
			if (ft_strcmp(tmp->lnk->ar[i], lem->end) == 0)
			{
				tmp->lnum = 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	find_path(t_lem *lem, int n)
{
	t_lst	*tmp;
	int		i;

	tmp = lem->lst;
	while (tmp)
	{
		i = 0;
		while (i < tmp->lnk->size)
		{
			if (ft_strcmp(tmp->lnk->ar[i], lem->end) == 0)
			{
				tmp->lnum = n;
				if (ft_strcmp(tmp->name, lem->start) == 0)
					lem->brek = 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	get_path(t_lem *lem)
{
	int n;

	n = 2;
	(void)lem;
	find_first_step(lem);
	while (lem->brek == 0)
	{
		find_path(lem, n);
		n++;
	}
}
