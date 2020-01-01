/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:05:50 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/12 15:44:06 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int a;

	a = 2;
	while (a <= nb / a)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int x;

	if (nb <= 0 || nb == 1)
		return (2);
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		x = ft_find_next_prime(nb + 1);
	return (x);
}
