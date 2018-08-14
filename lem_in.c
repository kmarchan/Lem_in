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

void	initialise(t_lem *lem)
{
	lem = (t_lem *)memaloc(sizeof(t_lem));
	lem->fd = 0;
	lem->ant = 0;
	lem->vec->size = 0;
	lem->vec->cap = 0;
}

int		main()
{
	t_lem *lem;
	initialise(lem);
	free(lem);
	exit(0);
}
