/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:41 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/20 08:35:28 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <string.h>

int		duplicates(char *nam, char **ar, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (ft_strcmp(ar[i], nam) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	dup_link(t_lem *lem, char *nam, char *link)
{
	t_lst *tmp;

	tmp = lem->lst;
	while (ft_strcmp(tmp->name, link) != 0 && tmp->next)
	{
		tmp = tmp->next;
	}
	if (duplicates(nam, tmp->lnk->ar, tmp->lnk->size))
	{
		if (tmp->lnk->size == tmp->lnk->cap)
		{
			vec_in(tmp->lnk);
		}
		tmp->lnk->ar[tmp->lnk->size] = ft_strdup(nam);
		(tmp->lnk->size)++;
	}
}

void	split_set(t_lst *lst, char *lin, t_lem *lem)
{
	char	**spl;
	t_lst	*tmp;

	(void)lem;
	tmp = lst;
	spl = ft_split_c(lin, '-');
	while (ft_strcmp(tmp->name, spl[0]) && tmp->next)
	{
		tmp = tmp->next;
	}
	if (duplicates(spl[1], tmp->lnk->ar, tmp->lnk->size))
	{
		if (tmp->lnk->size == tmp->lnk->cap)
		{
			vec_in(tmp->lnk);
		}
		tmp->lnk->ar[tmp->lnk->size] = ft_strdup(spl[1]);
		(tmp->lnk->size)++;
		dup_link(lem, spl[0], spl[1]);
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
			split_set(tmp, lem->vec->ar[i], lem);
		}
		i++;
	}
	// tmp->lnk->ar[tmp->lnk->size] = NULL;
}
