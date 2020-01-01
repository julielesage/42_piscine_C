/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:56:25 by jlesage           #+#    #+#             */
/*   Updated: 2019/08/31 18:03:12 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putnbr(int nb)
{
	int a;
	int b;

	a = 1;
	if (nb <0)
	{
		nb = -nb
	}
	nb = a + 48;
	write(1, &nb, 1);
}

int main (nb)
{
	ft_putnbr(42);
	return (0);
}