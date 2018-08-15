/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:47:34 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/15 10:54:32 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_word_count(char const *s)
{
	size_t		w;
	size_t		i;

	w = 0;
	i = 0;
	if (!s)
		return (0);
	if (!ft_isspace(s[i]))
		w++;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]) && s[i + 1] != '\0')
			w++;
		i++;
	}
	return (w);
}
