/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:57:46 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/09 14:44:05 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	size = i + 1;
	while (dest[i] && src[j])
		if (i < size)
		{
			i++;
		}
	while (src[j] && i < size)
	{
		dest[i + j] = src[j];
		j++;
		i++;
	}
	size = i + j;
	return (size);
}
int main(void)
{ 
	char dest[] = "salut";
	char src[] = "cava";

	printf("%d\n", ft_strlcat(dest, src, 8));
	printf("%d\n", strlcat(dest, src, 8));
			return (0);
}
