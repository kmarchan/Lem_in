/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:38:50 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 13:07:43 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		find_val(t_lem *lem, char *name)
{
	t_lst *tmp;

	tmp = lem->lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			return (tmp->lnum);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_lst	*stone(t_lem *lem, char *name)
{
	t_lst	*tmp;

	tmp = lem->lst;
	while (ft_strcmp(tmp->name, name) != 0)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_lst	*set_stone(t_lem *lem, t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*low;
	int		score;
	int		hold;
	int		i;

	tmp = lst;
	i = 0;
	hold = 0;
	score = INT_MAX;
	low = NULL;
	while (i < tmp->lnk->size)
	{
		if (ft_strcmp(tmp->lnk->ar[i], lem->end) == 0)
			return (tmp);
		hold = find_val(lem, tmp->lnk->ar[i]);
		if (hold < score && hold != 0)
		{
			score = hold;
			low = stone(lem, tmp->lnk->ar[i]);
		}
		i++;
	}
	return (low);
}

t_lst	*start(t_lem *lem)
{
	t_lst	*tmp;

	tmp = lem->lst;
	while (ft_strcmp(tmp->name, lem->start) != 0)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	print_ar(char **ar)
{
	int n;

	n = 0;
	while (ar[n] != '\0')
	{
		ft_putendl_fd(ar[n], 2);
		n++;
	}
}

int		path(t_lem *lem)
{
	t_lst	*tmp;
	t_lst	*step;
	int		i;
	int		end;

	i = 1;
	end = 1;
	tmp = start(lem);
	lem->route = (char **)ft_memalloc(sizeof(char *) * ft_lstlen(lem->lst) + 1);
	lem->route[0] = ft_strdup(tmp->name);
	while (end != 0)
	{
		step = set_stone(lem, tmp);
		if (step == NULL)
			return (0);
		lem->route[i] = ft_strdup(step->name);
		if (tmp->lnum == 1)
		{
			end = 0;
			lem->route[i] = ft_strdup(lem->end);
		}
		tmp = stone(lem, step->name);
		i++;
	}
	print_ar(lem->route);
	return (1);
}
