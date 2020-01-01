/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 02:42:32 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/18 14:20:16 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *base);
int		ft_mallocsize(int nbr, char *base_to);
int		checkbase(char *base);

char	*ft_putnbr_base(long nbr, char *base, char *tab)
{
	int i;
	int size_base;

	size_base = 0;
	i = 0;
	while (base[i])
	{
		size_base++;
		i++;
	}
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr = -nbr;
	}
	i = ft_mallocsize(nbr, base) - 1;
	tab[i + 1] = '\0';
	while (nbr > 0)
	{
		tab[i] = base[nbr % size_base];
		nbr = nbr / size_base;
		i--;
	}
	return (tab);
}

int		ft_mallocsize(int nbr, char *base_to)
{
	int res;

	res = 0;
	while (nbr > 0)
	{
		nbr = nbr / (ft_strlen(base_to));
		res++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*tab;
	int		nbdeci;

	if (!(checkbase(base_from)) || !(checkbase(base_to)))
		return (NULL);
	nbdeci = ft_atoi_base(nbr, base_from);
	if (nbdeci < 0)
	{
		if (!(tab = malloc(sizeof(char) * (ft_mallocsize(nbdeci, base_to)
							+ 2))))
			return (0);
	}
	else
	{
		if (!(tab = malloc(sizeof(char) * (ft_mallocsize(nbdeci, base_to)
							+ 1))))
			return (0);
	}
	return (ft_putnbr_base(nbdeci, base_to, tab));
}
