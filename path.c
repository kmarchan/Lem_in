/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:38:50 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 10:27:09 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

// void	creatpath(t_lem *lem, char *str)
// {
// 	char	*tmp;

// 	if (!lem->route)
// 	{
// 		lem->route = ft_strdup(str);
// 		return ;
// 	}
// 	tmp = ft_strdup(lem->route);
// 	free(lem->route);
// 	lem->route = ft_strjoin(tmp, str);
// 	free(tmp);
// }

// #include <stdio.h>
// void set_path(t_lem *lem)
// {
// 	ft_putendl_fd("SET", 2);
// 	int i;
// 	int score;
// 	t_lst *lst;
// 	t_lst *tmp;
// 	t_lst *nex;

// 	tmp = lem->lst;
// 	while (tmp->lnum != 1)
// 	{
// 		i = 0;
// 		score = INT_MAX;
// 		while (tmp->lnk->ar[i] && i < tmp->lnk->size)
// 		{
// 			lst = lem->lst;
// 			while (ft_strcmp(lst->name, tmp->lnk->ar[i]) != 0)
// 				lst = lst->next;
// 			// ft_putnbr_fd(lst->lnum, 2);
// 			// ft_putchar_fd(' ', 2);
// 			if (lst->lnum < score && lst->lnum != 0)
// 			{
// 				printf("name = %s\n", tmp->name);
// 				ft_putnbr_fd(score, 2);
// 				ft_putchar_fd(' ', 2);
// 				ft_putendl_fd(lst->name, 2);
// 				score = lst->lnum;
// 				nex = lst;
// 			}
// 			i++;
// 		}
// 		tmp = nex;
// 		creatpath(lem, tmp->name);
// 	}
// }

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

int		path(t_lem *lem)
{
	t_lst	*tmp;
	t_lst	*step;
	int		i;
	int		end;

	i = 0;
	end = 1;
	tmp = start(lem);
	lem->route = (char **)ft_memalloc(sizeof(char *) * ft_lstlen(lem->lst) + 1);
	lem->route[i] = ft_strdup(tmp->name);
	i++;
	while (end != 0)
	{
		step = set_stone(lem, tmp);
		if (step == NULL)
			return (0);
		lem->route[i] = ft_strdup(step->name);
		// ft_putendl_fd(lem->route[i], 2);
		if (tmp->lnum == 1)
		{
			end = 0;
			lem->route[i] = ft_strdup(lem->end);
		}
		tmp = stone(lem, step->name);
		i++;
	}
	int n = 0;
	while (n <= i)
	{
		ft_putstr_fd(lem->route[n], 2);
		ft_putchar_fd(' ', 2);
		n++;
	}
	ft_putchar_fd('\n', 2);
	return (1);
}
