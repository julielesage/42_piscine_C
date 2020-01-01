/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:36:02 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/10 18:04:24 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int rslt;
	int count;

	i = 0;
	rslt = 0;
	count = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f'))
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rslt = (rslt * 10) + (str[i] - 48);
		i++;
	}
	if (count % 2 == 1)
		rslt = rslt * -1;
	return (rslt);
}
