/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:42:17 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/18 23:26:34 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strntoncpy(char *src, int len)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	if (!(copy = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_issep(char c, char *charset)
{
	int	i;

	i = 0;
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_word_count(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], charset))
			i++;
		while (!ft_issep(str[i], charset) && str[i] != '\0')
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		size;
	int		len;
	char	**tab;

	i = 0;
	size = ft_word_count(str, charset);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	tab[size] = 0;
	while (i < size)
	{
		len = 0;
		while (ft_issep(*str, charset) && *str)
			str++;
		while (str[len] && !ft_issep(str[len], charset))
			len++;
		if (!(tab[i] = ft_strntoncpy(str, len)))
			return (NULL);
		str += len;
		i++;
	}
	return (tab);
}
