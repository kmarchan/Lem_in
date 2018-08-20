/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:38:50 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/20 17:33:44 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	creatpath(t_lem *lem, char *str)
{
	char	*tmp;

	if (!lem->route)
	{
		lem->route = ft_strdup(str);
		return ;
	}
	tmp = ft_strdup(lem->route);
	free(lem->route);
	lem->route = ft_strjoin(tmp, str);
	free(tmp);
}

void set_path(t_lem *lem)
{
	ft_putendl_fd("SET", 2);
	int i;
	int score;
	t_lst *lst;
	t_lst *tmp;
	t_lst *nex;

	tmp = lem->lst;
	while (tmp->lnum != 1)
	{
		i = 0;
		score = INT_MAX;
		while (tmp->lnk->ar[i] && i < tmp->lnk->size)
		{
			lst = lem->lst;
			while (ft_strcmp(lst->name, tmp->lnk->ar[i]) != 0)
				lst = lst->next;
			if (lst->lnum < score && lst->lnum != 0)
			{
				score = lst->lnum;
				nex = lst;
			}
			i++;
		}
		tmp = nex;
		creatpath(lem, tmp->name);
	}
}

void	path(t_lem *lem)
{
	set_path(lem);
	ft_putendl_fd(lem->route, 2);
}
