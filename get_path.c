/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:11:42 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 17:18:32 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	set_lnum(t_lem *lem, char *link, int num)
{
	t_lst *tmp;

	tmp = lem->lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, link) == 0 && tmp->lnum == 0)
		{
			tmp->lnum = num + 1;
		}
		tmp = tmp->next;
	}
}

void	path_next(t_lem *lem)
{
	t_lst	*tmp;
	t_lst	*tmp1;
	int		i;

	tmp = lem->lst;
	tmp1 = lem->lst;
	while (tmp1)
	{
		tmp = lem->lst;
		while (tmp)
		{
			i = 0;
			if (tmp->lnum > 0)
			{
				while (i < tmp->lnk->size)
				{
					set_lnum(lem, tmp->lnk->ar[i], tmp->lnum);
					i++;
				}
			}
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
}

void	find_path(t_lem *lem)
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

void	get_path(t_lem *lem)
{
	(void)lem;
	find_path(lem);
	path_next(lem);
}
