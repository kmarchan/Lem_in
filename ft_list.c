/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 07:39:19 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 19:11:08 by kmarchan         ###   ########.fr       */
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
	new->link = NULL;
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

// void		del_extra(t_lst *lst)
// {
// 	t_lst *tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (tmp->next->norm < 0)
// 			tmp->next = NULL;
// 		tmp = tmp->next;
// 	}
// 	free(tmp);
// }
