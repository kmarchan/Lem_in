/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:45:47 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 15:01:16 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		ft_arlen(char **ar)
{
	int		i;

	i = 0;
	while (ar[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	print_ant(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	release_ants(t_lem *lem)
{
	int	*pth;
	int	len;
	int	i;
	int	j;

	j = 1;
	print_ar(lem->vec->ar);
	len = ft_arlen(lem->route);
	pth = (int *)ft_memalloc(sizeof(int) * len - 1);
	pth[0] = lem->ant;
	while (pth[len - 1] < lem->ant)
	{
		i = len - 1;
		while (i > 0)
		{
			if (pth[i - 1] > pth[i])
			{
				pth[i]++;
			}
			if (pth[i] > 0 && i > 0)
				print_ant(pth[i], lem->route[i]);
			if (ft_strcmp(lem->route[i], lem->end) == 0 && pth[i] == lem->ant)
			{
				ft_putchar('\n');
				return ;
			}
			i--;
		}
		i = 1;
		// while (i < len)
		// {
		// 	if (pth[i] > 0)
		// 		print_ant(pth[i], lem->route[i]);
		// 	// ft_putnbr_fd(pth[i], 2);
		// 	// ft_putchar_fd(' ', 2);
		// 	i++;
		// }
		ft_putchar_fd('\n', 2);
	}
}
