/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 12:45:47 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 13:41:22 by kmarchan         ###   ########.fr       */
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

// void	release_ants(t_lem *lem)
// {
// 	int	*pth;
// 	int	len;
// 	int i;
// 	int j;

// 	// i = 0;
// 	j = 1;
// 	print_ar(lem->vec->ar);
// 	len = ft_arlen(lem->route);
// 	pth = (int *)ft_memalloc(sizeof(int) * len);
// 	pth[0] = lem->ant;
// 	// ft_putnbr_fd(pth[0], 2);
// 	ft_putchar_fd('-', 2);
// 	ft_putnbr_fd(lem->ant, 2);
// 	ft_putchar_fd('\n', 2);
// 	while (pth[len] < lem->ant)
// 	{
// 		i = 1;
// 		ft_putnbr_fd(pth[i], 2);
// 		ft_putchar_fd('\n', 2);
// 		while (i <= len)
// 		{
// 			if (pth[i] < pth[i] - 1)
// 			{
// 				pth[i]++;
// 			}
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (i <= len)
// 	{
// 		ft_putnbr_fd(pth[i], 2);
// 		ft_putchar_fd(' ', 2);
// 		i++;
// 	}
// }

void	release_ants(t_lem *lem)
{
	int	*pth;
	int	len;
	int i;
	int j;

	// i = 0;
	j = 1;
	print_ar(lem->vec->ar);
	len = ft_arlen(lem->route);
	pth = (int *)ft_memalloc(sizeof(int) * len);
	pth[0] = lem->ant;
	// ft_putnbr_fd(pth[0], 2);
	// ft_putchar_fd('-', 2);
	// ft_putnbr_fd(lem->ant, 2);
	// ft_putchar_fd('\n', 2);
	while (pth[len] < lem->ant)
	{
		i = len;
		// ft_putnbr_fd(pth[i], 2);
		// ft_putchar_fd('\n', 2);
		while (i)
		{
			if (pth[i - 1] > pth[i])
			{
				ft_putendl_fd("IF", 2);
				pth[i]++;
			}
			i--;
		}
		i = 0;
	while (i <= len)
	{
		ft_putnbr_fd(pth[i], 2);
		ft_putchar_fd(' ', 2);
		i++;
	
	}
	}
	
}
