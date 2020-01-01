/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:44:53 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/19 23:27:44 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_issep(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		while (str[i] && ft_issep(str[i], charset))
			i++;
		if (str[i])
		{
			while (str[i] && !ft_issep(str[i], charset))
				i++;
			nb_words++;
		}
	}
	return (nb_words);
}

char	*ft_strndup(char *src, int len)
{
	char		*dup;
	int			i;

	if (!src)
		return (NULL);
	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char		**tab;
	int			size;
	int			i;
	int			len;

	size = ft_count_words(str, charset);
	if (!(tab = (char **)malloc(sizeof(char ) * (size + 1))))
		return (NULL);
	tab[size] = 0;
	i = 0;
	while (i < size)
	{
		len = 0;
		while (*str && ft_issep(*str, charset))
			str++;
		while (str[len] && !ft_issep(str[len], charset))
			len++;
		if (!(tab[i] = ft_strndup(str, len)))
			return (NULL);
		str += len;
		i++;
	}
	return (tab);
}
