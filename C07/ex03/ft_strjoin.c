/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:02:34 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/19 14:16:58 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *strs)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (strs[i])
	{
		i++;
		count++;
	}
	return (count);
}

int		ft_strlenglobalstrs(char **strs, int size)
{
	int i;
	int globalstrsize;

	i = 0;
	globalstrsize = 0;
	while (i < size)
	{
		globalstrsize = globalstrsize + ft_strlen(strs[i]);
		i++;
	}
	return (globalstrsize);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	if (dest[i] == '\0')
	{
		while (src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strsfinal;
	int		i;

	if (size == 0)
	{
		if (!(strsfinal = malloc(sizeof(char) * 1)))
			return (0);
		strsfinal[0] = '\0';
		return (strsfinal);
	}
	if (!(strsfinal = malloc(sizeof(char) * (((ft_strlen(sep) * (size - 1))
		+ (ft_strlenglobalstrs(strs, size) + 1))))))
		return (0);
	i = 0;
	strsfinal[0] = '\0';
	while (i < size)
	{
		strsfinal = ft_strcat(strsfinal, strs[i]);
		if (i < (size - 1))
			strsfinal = ft_strcat(strsfinal, sep);
		i++;
	}
	return (strsfinal);
}
