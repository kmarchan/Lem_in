/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:41 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 13:02:40 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <string.h>

// void	get_links(t_lem *lem)
// {
// 	t_lst	*tmp;
// 	char	**spl;
// 	int		i;

// 	i = 0;
// 	tmp = lem->lst;
// 	while (lem->vec->ar[i] != NULL)
// 	{
// 		if (ft_word_count(lem->vec->ar[i]) == 1 &&
// 		ft_strchr(lem->vec->ar[i], '-') && lem->vec->ar[i][0] != '#')
// 		{
// 			ft_putendl_fd("W", 2);
// 			ft_putendl_fd(lem->vec->ar[i], 2);
// 			spl = ft_strsplit(lem->vec->ar[i], '-');
// 			ft_putendl_fd("A", 2);
// 			while (ft_strcmp(tmp->name, spl[0]))
// 			{
// 				ft_putendl_fd("B", 2);
// 				tmp = tmp->next;
// 			}
// 			ft_putendl_fd("C", 2);
// 			if (ft_strcmp(tmp->name, spl[0]) == 0)
// 			{
// 				ft_putendl_fd("D", 2);
// 				if (tmp->lnk->size == tmp->lnk->cap)
// 				{
// 					ft_putendl_fd("E", 2);
// 					vec_in(tmp->lnk);
// 				}
// 				ft_putendl_fd("F", 2);
// 				tmp->lnk->ar[tmp->lnk->size] = ft_strdup(spl[1]);
// 				ft_putendl_fd("G", 2);
// 				ft_putendl_fd(tmp->lnk->ar[tmp->lnk->size], 2);
// 				(tmp->lnk->size)++;
// 				ft_putnbr_fd(tmp->lnk->size, 2);
// 				ft_putendl_fd("H", 2);
// 				// tmp->lnk->size += 1;
// 			}
// 		}
// 		i++;
// 	}
// 	tmp->lnk->ar[tmp->lnk->size] = NULL;
// }

void	split_set(t_lst *tmp, char *lin)
{
	char	**spl;

	spl = ft_split_c(lin, '-');
			while (ft_strcmp(tmp->name, spl[0]))
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
	// char	**spl;
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
			// spl = ft_split_c(lem->vec->ar[i], '-');
			// while (ft_strcmp(tmp->name, spl[0]))
			// {
			// 	tmp = tmp->next;
			// }
			// if (ft_strcmp(tmp->name, spl[0]) == 0)
			// {
			// 	if (tmp->lnk->size == tmp->lnk->cap)
			// 	{
			// 		vec_in(tmp->lnk);
			// 	}
			// 	tmp->lnk->ar[tmp->lnk->size] = ft_strdup(spl[1]);
			// 	(tmp->lnk->size)++;
			// }
		}
		i++;
	}
	tmp->lnk->ar[tmp->lnk->size] = NULL;
}

void	find_route(t_lem *lem)
{
	
}