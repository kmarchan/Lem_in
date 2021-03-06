/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:24 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 18:38:58 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

void	get_ants(t_lem *lem)
{
	int	i;

	i = 0;
	if (ft_word_count(lem->vec->ar[i]) == 1 && is_all_digit(lem->vec->ar[i]))
	{
		lem->ant = (ft_atoi(lem->vec->ar[i]));
	}
}
