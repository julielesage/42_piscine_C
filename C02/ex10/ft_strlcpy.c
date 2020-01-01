/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:17:48 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/04 19:22:31 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	if (size != '\0')
	{
		while (i < size - 1)
		{
			if (src[i] != '\0')
				dest[i] = src[i];
			else
				break ;
			i++;
		}
		while (i < size)
		{
			dest[i] = '\0';
			i++;
		}
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
