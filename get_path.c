/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:11:42 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/20 08:35:49 by kmarchan         ###   ########.fr       */
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
		ft_putstr_fd(tmp->name, 2);
		ft_putchar_fd('	', 2);
		ft_putendl_fd(link, 2);
		if (ft_strcmp(tmp->name, link) == 0 && tmp->lnum == 0)
		{
			ft_putendl_fd("LNUM", 2);
			tmp->lnum = num + 1;
		}
		tmp = tmp->next;
	}
}

void	path_next(t_lem *lem)
{
	t_lst	*tmp;
	int		i;

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
				// path_next(lem);
			}
			i++;
		}
		tmp = tmp->next;
	}
}

// void	find_path(t_lem *lem, int n)
// {
// 	t_lst	*tmp;
// 	int		i;

// 	tmp = lem->lst;
// 	while (tmp)
// 	{
// 		i = 0;
// 		while (i < tmp->lnk->size)
// 		{
// 			if (ft_strcmp(tmp->lnk->ar[i], lem->end) == 0)
// 			{
// 				tmp->lnum = n;
// 				if (ft_strcmp(tmp->name, lem->start) == 0)
// 					lem->brek = 1;
// 			}
// 			i++;
// 		}
// 		tmp = tmp->next;
// 	}
// }

void	get_path(t_lem *lem)
{
	// int n;

	// n = 2;
	(void)lem;
	ft_putendl_fd("get_path", 2);
	// ft_putendl_fd("f", 2);
	find_path(lem);
	// ft_putendl_fd("n", 2);
	path_next(lem);
	// ft_putendl_fd("e", 2);
	// while (lem->brek == 0)
	// {
	// 	find_path(lem, n);
	// 	n++;
	// }
}
