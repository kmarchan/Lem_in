/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:38:50 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/20 14:58:33 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

// void	set_path(t_lem *lem)
// {
// 	ft_putendl_fd("set", 2);
// 	t_lst	*tmp;
// 	char	**ar;
// 	int		i;

// 	i = 0;
// 	int ll;
// 	tmp = lem->lst;
// 	int l = ft_lstlen(tmp);
// 	ll = l;
// 	ar = (char **)ft_memalloc(sizeof(char *) * l);
// 	while (ll--)
// 	{
// 		tmp = lem->lst;
// 		if (i == 0)
// 			{
// 				ar[0] = ft_strdup(lem->end);
// 				i++;
// 			}
// 		while (tmp)
// 		{
// 			if (tmp->lnum == i && ft_strcmp(tmp->name, lem->end) != 0)
// 			{
// 				ar[i] = ft_strdup(tmp->name);
// 				i++;
// 				ft_putendl_fd("1", 2);
// 				// if (ft_strcmp(ar[i], lem->start) == 0)
// 				// 	break ;
// 				ft_putendl_fd("1b", 2);
// 			}
// 			ft_putendl_fd("2", 2) ;
// 			tmp = tmp->next;
// 		}
// 	}
// 	// ft_putendl_fd("3", 2);
// 	int n = 0;
// 	// ft_putnbr_fd(i, 2);
// 	// ft_putchar_fd(' ', 2);
// 	// ft_putnbr_fd(n, 2);
// 	while (n < i)
// 	{
// 		ft_putnbr_fd(i, 2);
// 		ft_putchar_fd(' ', 2);
// 		ft_putnbr_fd(n, 2);
// 		ft_putchar_fd('\n', 2);
// 		ft_putendl_fd(ar[n], 2);
// 		n++;
// 	}
// }

void	set_path(t_lem *lem)
{
	ft_putendl_fd("set", 2);
	t_lst	*tmp;
	t_lst	*low;
	char	**ar;
	int		i;

	i = 0;
	int ll;
	tmp = lem->lst;
	int l = ft_lstlen(tmp);
	low = NULL;
	ll = l;
	ar = (char **)ft_memalloc(sizeof(char *) * l);
	while (ll--)
	{
		if (i == 0)
			{
				ar[0] = ft_strdup(lem->start);
				i++;
			}
		tmp = lem->lst;
		while (tmp)
		{
			if (tmp->lnum < low->lnum && ft_strcmp(tmp->name, lem->start) != 0)
			{
				low = tmp;
				// ar[i] = ft_strdup(tmp->name);
				// i++;
				// ft_putendl_fd("1", 2);
				// // if (ft_strcmp(ar[i], lem->start) == 0)
				// // 	break ;
				// ft_putendl_fd("1b", 2);
			}
			// ft_putendl_fd("2", 2) ;
			tmp = tmp->next;
		}
	}
	// ft_putendl_fd("3", 2);
	int n = 0;
	// ft_putnbr_fd(i, 2);
	// ft_putchar_fd(' ', 2);
	// ft_putnbr_fd(n, 2);
	while (n < i)
	{
		ft_putnbr_fd(i, 2);
		ft_putchar_fd(' ', 2);
		ft_putnbr_fd(n, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd(ar[n], 2);
		n++;
	}
}

void	path(t_lem *lem)
{
	set_path(lem);
}
