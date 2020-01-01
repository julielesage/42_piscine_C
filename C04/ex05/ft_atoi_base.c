/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:34:26 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/11 00:22:03 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			ft_verifbase(char *base, int size_base)
{
	int i;
	int j;

	i = 0;
	if (size_base <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == 32 || base[i] == '\t' || base[i] == '\n'
				|| base[i] == '\v' || base[i] == '\r' || base[i] == '\f'
				|| base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int			ft_norme(char *str, int i, char *base)
{
	int j;
	int rslt;
	int m;

	rslt = 0;
	while (str[i])
	{
		m = 0;
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				rslt = rslt * ft_strlen(base) + j;
				m = 1;
			}
			j++;
		}
		if (m == 0)
			break ;
		i++;
	}
	return (rslt);
}

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int rslt;
	int count;

	rslt = 0;
	count = 1;
	i = 0;
	if (ft_verifbase(base, ft_strlen(base)))
	{
		while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
					|| str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
					|| str[i] == '\f'))
			i++;
		while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				count = -count;
			i++;
		}
		rslt = ft_norme(str, i, base);
	}
	return (rslt * count);
}
int main (int ac, char ** av)
{
	printf("%d \n", ft_atoi_base(av[1], av[2]));
	return (0);
}
