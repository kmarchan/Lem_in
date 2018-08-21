/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:37:49 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 17:23:58 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_lem	*initialise(void)
{
	t_lem *lem;

	lem = (t_lem *)ft_memalloc(sizeof(t_lem));
	lem->vec = (t_vec *)ft_memalloc(sizeof(t_vec));
	if (!lem)
	{
		return (NULL);
	}
	lem->fd = 0;
	lem->ant = 0;
	lem->brek = 0;
	lem->vec->size = 0;
	lem->vec->cap = 0;
	return (lem);
}

int		errors0(t_lem *lem)
{
	if (lem->ant < 1)
	{
		ft_putendl_fd(RED "Invalid Ants" RESET, 2);
		return (1);
	}
	return (0);
}

int		errors1(t_lem *lem)
{
	if (lem->end == NULL || lem->start == NULL)
	{
		ft_putendl_fd(RED "Invalid Start or End" RESET, 2);
		return (1);
	}
	return (0);
}

int		errors2(t_lem *lem)
{
	t_lst *tmp;

	tmp = start(lem);
	if (tmp->lnum < 1 || tmp->lnk->size == 0)
	{
		ft_putendl_fd(RED "Invalid Start or End" RESET, 2);
		return (0);
	}
	return (0);
}

int		main(void)
{
	t_lem	*lem;

	lem = initialise();
	read_file(lem);
	get_ants(lem);
	if (errors0(lem))
		exit(0);
	analyze(lem);
	if (errors1(lem))
		exit(0);
	get_path(lem);
	if (errors2(lem) || !path(lem))
		exit(0);
	release_ants(lem);
	ft_putchar('\n');
	exit(1);
}
