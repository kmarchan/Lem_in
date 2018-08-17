/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:41 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/17 10:13:51 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <string.h>

void	dup_link(t_lem *lem, char *nam, char *link)
{
	t_lst *tmp;

	tmp = lem->lst;
	// ft_putendl_fd(tmp->name, 2);
	// ft_putendl_fd(link, 2);
	while (ft_strcmp(tmp->name, link) && tmp)
	{
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, link) == 0)
	{
		if (tmp->lnk->size == tmp->lnk->cap)
		{
			vec_in(tmp->lnk);
		}
		tmp->lnk->ar[tmp->lnk->size] = ft_strdup(nam);
		(tmp->lnk->size)++;
	}
}

void	split_set(t_lst *tmp, char *lin)
{
	char	**spl;

	spl = ft_split_c(lin, '-');
	while (ft_strcmp(tmp->name, spl[0]) && tmp)
	{
		tmp = tmp->next;
	}
	if (ft_strcmp(tmp->name, spl[0]) == 0)
	{	
		if (tmp->lnk->size == tmp->lnk->cap)
		{
			vec_in(tmp->lnk);
		}
		tmp->lnk->ar[tmp->lnk->size] = ft_strdup(spl[1]);
		(tmp->lnk->size)++;
	}
}

void	get_links(t_lem *lem)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lem->lst;
	while (lem->vec->ar[i] != NULL)
	{
		tmp = lem->lst;
		if (ft_word_count(lem->vec->ar[i]) == 1 &&
		ft_strchr(lem->vec->ar[i], '-') && lem->vec->ar[i][0] != '#')
		{
			split_set(tmp, lem->vec->ar[i]);
			// ft_putendl_fd("H", 2);
			// dup_link(lem, tmp->lnk->ar[tmp->lnk->size - 1], tmp->name);
			dup_link(lem, tmp->name, tmp->lnk->ar[tmp->lnk->size - 1]);
			// ft_putendl_fd("I", 2);
		}
		i++;
	}
	tmp->lnk->ar[tmp->lnk->size] = NULL;
}

// void	find_first_step(t_lem *lem)
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
// 				tmp->lnum = 1;
// 			}
// 			i++;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void	find_path(t_lem *lem, char *name, int n)
// {
// 	t_lst	*tmp;
// 	int		i;
// 	char	*link;

// 	link = ft_strdup(name);
// 	tmp = lem->lst;
// 	while (tmp)
// 	{
// 		i = 0;
// 		while (i < tmp->lnk->size)
// 		{
// 			if (ft_strcmp(tmp->lnk->ar[i], lem->end) == 0)
// 			{
// 				tmp->lnum = n;
// 			}
// 			i++;
// 		}
// 	}
// }
