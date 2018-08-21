/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:21:39 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 17:19:40 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	free_ar(char **ar, int n)
{
	int e;

	e = 0;
	while (e < n)
	{
		free(ar[e]);
		e++;
	}
	free(ar);
}

void	print_ar(char **ar)
{
	int n;

	n = 0;
	while (ar[n] != '\0')
	{
		ft_putendl_fd(ar[n], 1);
		n++;
	}
	ft_putchar('\n');
}

void	free_all(t_lem *lem)
{
	free_ar(lem->vec->ar, lem->vec->cap);
	free(lem->vec);
	free_lst(lem->lst);
	free(lem->lst);
	free(lem);
}

void	free_lst(t_lst *lst)
{
	if (lst->next)
	{
		free_ar(lst->lnk->ar, lst->lnk->cap);
		free(lst->lnk);
		free_lst(lst->next);
	}
	free(lst);
}
