/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:37:49 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/14 08:55:19 by kmarchan         ###   ########.fr       */
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
	lem->vec->size = 0;
	lem->vec->cap = 0;
	return (lem);
}

int		main(void)
{
	t_lem *lem;

	// ft_putstr_fd("MAIN", 2);
	lem = initialise();
	// lem = (t_lem *)ft_memalloc(sizeof(t_lem));
	// if (!lem)
	// {
	// 	return (0);
	// }
	// lem->fd = 0;
	// lem->ant = 0;
	// ft_putstr_fd("B", 2);
	// lem->vec = (t_vec *)ft_memalloc(sizeof(t_vec));
	// lem->vec->size = 0;
	// ft_putstr_fd("C", 2);
	// lem->vec->cap = 0;
	// ft_putstr_fd("C", 2);
	// ft_putstr_fd("1", 2);
	read_file(lem);
	// int n = 0;
	// while (n <= lem->vec->cap)
	// {
	// 	ft_putendl(lem->vec->ar[n]);
	// 	n++;
	// }
	free(lem);
	exit(1);
}
