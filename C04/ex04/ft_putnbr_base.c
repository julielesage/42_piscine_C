/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:39:32 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/10 15:33:56 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* • Écrire une fonction qui affiche un nombre dans le terminal dans une base donnée.
• Ce nombre est fourni sous la forme d’un int et la base sous la forme d’une chaîne
de caractères.
• La base contient tous les symboles utilisables pour afficher le nombre :
◦ 0123456789 est la base couramment utilisée pour représenter nos nombres
décimaux ;
◦ 01 est une base binaire ;
◦ 0123456789ABCDEF est une base hexadecimale ;
◦ poneyvif est une base octale.
• La fonction doit gérer les nombres négatifs.
• Si un paramètre contient une erreur la fonction n’affiche rien. Une erreur peut
être :
◦ base est vide ou est de taille 1 ;
◦ base contient deux fois le même caractère ;
◦ base contient les caractères + ou -.*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_verifbase(char *base, int size_base)
{
	int i;
	int j;

	i = 0;
	if (size_base <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	while (base[i])
		j = i + 1;
	while (base[j])
	{
		if (base[i] == base[j])
			return (0);
		j++;
	}
	i++;
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int		size_base;
	unsigned int		n;
	int					i;

	i = 0;
	n = nbr;
	size_base = 0;
	while (base[size_base] != '\0')
		size_base++;
	if (ft_verifbase(base, size_base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = (unsigned int)-nbr;
		}
		else
			n = (unsigned int)nbr;
		if (n >= size_base)
			ft_putnbr_base(n / size_base, base);
		ft_putchar(base[((n % size_base))]);
	}
}
