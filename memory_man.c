/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:21:39 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 09:31:40 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

// void	bzero_array(char **ar, int n)
// {
// 	int line;

// 	line = 0;
// 	while (line < n)
// 	{
// 		ft_bzero(ar[line], n);
// 		line++;
// 	}
// }

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

void	free_lst(t_lst *lst)
{
	if (lst->next)
		free_lst(lst->next);
	free(lst);
}
