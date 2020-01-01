/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:29:25 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/04 15:21:10 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_le(char str)
{
	if (str >= 97 && str <= 122)
		return (0);
	else if (str >= 65 && str <= 90)
		return (1);
	else if (str >= 48 && str <= 57)
		return (2);
	else
		return (3);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (ft_le(str[0]) == 0)
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (ft_le(str[i]) == 0 && (ft_le(str[i - 1]) == 3))
		{
			str[i] = str[i] - 32;
		}
		if (ft_le(str[i]) == 1 && ((ft_le(str[i - 1])) == 1
			|| (ft_le(str[i - 1]) == 0) || (ft_le(str[i - 1]) == 2)))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
