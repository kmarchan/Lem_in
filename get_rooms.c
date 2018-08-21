/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:39:13 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/21 16:38:18 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

char	*set_point(char *lin)
{
	char	**tmp;

	tmp = ft_split(lin);
	if (is_all_digit(tmp[1]) && is_all_digit(tmp[2]))
	{
		free(tmp[1]);
		free(tmp[2]);
		return (tmp[0]);
	}
	free_ar(tmp, 3);
	return (NULL);
}

void	find_begend(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->vec->ar[i] != NULL)
	{
		while (!ft_strstr(lem->vec->ar[i], "##"))
		{
			i++;
			if (lem->vec->ar[i] == NULL)
				return ;
		}
		if (ft_strcmp(lem->vec->ar[i], "##start") == 0 &&
		ft_word_count(lem->vec->ar[i + 1]) == 3 && lem->vec->ar[i + 1] != NULL)
		{
			lem->start = set_point(lem->vec->ar[i + 1]);
		}
		else if (ft_strcmp(lem->vec->ar[i], "##end") == 0 &&
		ft_word_count(lem->vec->ar[i + 1]) == 3 && lem->vec->ar[i + 1] != NULL)
		{
			lem->end = set_point(lem->vec->ar[i + 1]);
		}
		i++;
	}
}

int		get_rooms(t_lem *lem)
{
	int		i;
	int		e;
	char	**temp;
	t_lst	*hold;
	t_lst	*hold2;

	i = 0;
	e = 0;
	hold = lem->lst;
	hold = ft_lstnew();
	hold2 = hold;
	while (lem->vec->ar[i] != NULL)
	{
		if (ft_word_count(lem->vec->ar[i]) == 3 &&
		lem->vec->ar[i][0] != 'L' && lem->vec->ar[i][0] != '#')
		{
			e = 1;
			if (lem->vec->ar[i + 1] != NULL)
				hold->next = ft_lstnew();
			temp = ft_split(lem->vec->ar[i]);
			hold->name = ft_strdup(temp[0]);
			hold = hold->next;
			free_ar(temp, 3);
		}
		i++;
	}
	if (!e)
		return (0);
	lem->lst = hold2;
	del_extra(lem->lst);
	return (1);
}
