/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:16 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/04 22:31:36 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *dest)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (dest[i] != '\0')
	{
		count++;
		dest++;
	}
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}
