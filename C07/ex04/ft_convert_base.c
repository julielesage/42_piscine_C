/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 01:03:50 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/17 19:30:34 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* • Écrire une fonction qui renvoie le résultat de la conversion de la chaîne nbr exprimée en une base base_from dans une base base_to.
• nbr, base_from, base_to ne seront pas forcement modifiable.
• nbr suivra les m ˆme règles que ft_atoi_base. Attention donc au ’+’, ’-’ et aux
whitespaces.
• Le nombre representé par nbr tient dans un int.
• Si une base est incorrecte, la fonction renverra NULL.
• Le nombre retourné doit être préfixé seulement par un seul et unique ’-’ si c’est
nécessaire, pas de whitespaces ou de ’+’.*/

#include <stdlib.h>
#include <stdio.h>

int	checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '\r' || base[i] == '\t' || base[i] == 32
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '+' || base[i] == '-')
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

int	ft_strlen(char *base)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (base[i])
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_conversion(char *str, int i, char *base)
{
	int res;
	int m;
	int j;

	res = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		m = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				res = res * ft_strlen(base) + j;
				m = 1;
			}
			j++;
		}
		if (m == 0)
			break ;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int count;
	int res;

	count = 0;
	i = 0;
	while (str[i] && (str[i] == '\r' || str[i] == '\n' || str[i] == 32
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\t'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	res = ft_conversion(str, i, base);
	if (count % 2 == 1)
		res *= -1;
	return (res);
}
