/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:58:54 by kmarchan          #+#    #+#             */
/*   Updated: 2018/08/16 12:22:41 by kmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

static int			ft_strc(char const *s, char c)
{
	int		i;
	int		count;
	int		len;

	len = ft_strlen(s);
	i = 0;
	count = 0;
	while (i < len)
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static void			ft_strpull(int w, char **ret, char *str, char c)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	ret[w] = (char*)malloc(len + 1);
	while (i < len)
	{
		ret[w][i] = *str;
		i++;
		str++;
	}
	ret[w][i] = '\0';
}

char				**ft_split_c(char *str, char c)
{
	int		words;
	char	**ret;
	int		i;

	words = ft_strc(str, c);
	ret = (char**)malloc(sizeof(*ret) * words + 1);
	i = 0;
	while (i < words)
	{
		while (*str == c && *str != '\0')
			str++;
		ft_strpull(i, ret, str, c);
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	ret[words] = NULL;
	return (ret);
}
