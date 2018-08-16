/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:37:49 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 13:35:49 by kmarchan         ###   ########.fr       */
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
	int		n;
	t_lem	*lem;

	lem = initialise();
	read_file(lem);
	get_ants(lem);
	analyze(lem);
	if (errors(lem))
	{
		ERROR;
		exit(0);
	}
	n = 0;
	
	// while (lem->vec->ar[n] != NULL)
	// {
	// 	ft_putendl(lem->vec->ar[n]);
	// 	n++;
	// }
	// // free_all(lem);
	exit(1);
}
