/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 07:39:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/17 07:25:17 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*ft_lstnew(void)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
	{
		return (NULL);
	}
	new->lnum = 0;
	new->name = NULL;
	new->next = NULL;
	new->lnk = (t_vec *)malloc(sizeof(t_vec));
	new->lnk->cap = 0;
	new->lnk->size = 0;
	new->lnk->ar = NULL;
	return (new);
}

int			ft_lstlen(t_lst *lst)
{
	int		c;
	t_lst	*tmp;

	c = 0;
	tmp = lst;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	lst = tmp;
	return (c);
}

int			acending(int a, int b)
{
	return (a <= b);
}

void		del_extra(t_lst *lst)
{
	t_lst *tmp;
	t_lst *fre;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next->name == NULL)
		{
			fre = tmp->next;
			tmp->next = NULL;
		}
		tmp = tmp->next;
	}
	free(fre);
	free(tmp);
}
