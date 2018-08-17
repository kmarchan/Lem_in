/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:37:49 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/17 12:20:03 by kmarchan         ###   ########.fr       */
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

void	free_all(t_lem *lem)
{
	free_ar(lem->vec->ar, lem->vec->cap);
	free(lem->vec);
	// free_ar(lem->lst->lnk->ar);
	free_lst(lem->lst);
	free(lem->lst);
	free(lem);
}

int		errors(t_lem *lem)
{
	if (lem->ant < 1 || lem->end == NULL || lem->start == NULL)
		return (1);
	return (0);
}

int		main(void)
{
	t_lem	*lem;
	t_lst	*hold;
	// int		n;

	lem = initialise();
	// ft_putendl_fd("B", 2);
	read_file(lem);
	// ft_putendl_fd("C", 2);
	get_ants(lem);
	// ft_putendl_fd("D", 2);
	analyze(lem);
	// ft_putendl_fd("E", 2);
	get_path(lem);
	// ft_putendl_fd("F", 2);
	if (errors(lem))
	{
		ERROR;
		exit(0);
	}
	int i;
	ft_putstr_fd(CYN "ants = " RESET, 2);
	ft_putnbr_fd(lem->ant, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd(CYN "start = " RESET, 2);
	ft_putendl_fd(lem->start, 2);
	ft_putstr_fd(CYN "end = " RESET, 2);
	ft_putendl_fd(lem->end, 2);
	ft_putendl_fd(CYN "ROOMS:" RESET, 2);
	hold = lem->lst;
	while (lem->lst != NULL)
	{
		i = 0;
		ft_putstr_fd(CYN, 2);
		ft_putendl_fd(lem->lst->name, 2);
		ft_putstr_fd(RESET, 2);
		ft_putstr_fd(MAG, 2);
		ft_putnbr_fd(lem->lst->lnum, 2);
		ft_putstr_fd(RESET, 2);
		while (i < lem->lst->lnk->size)
		{
			ft_putstr_fd(lem->lst->lnk->ar[i], 2);
			ft_putchar_fd(' ', 2);
			i++;
		}
		ft_putchar_fd('\n', 2);
		lem->lst = lem->lst->next;
	}
	ft_putendl_fd(lem->end, 2);
	lem->lst = hold;
	// n = 0;
	
	// while (lem->vec->ar[n] != NULL)
	// {
	// 	ft_putendl(lem->vec->ar[n]);
	// 	n++;
	// }
	// // free_all(lem);
	exit(1);
}
