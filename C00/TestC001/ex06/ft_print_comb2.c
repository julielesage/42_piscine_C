/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:36:43 by jlesage           #+#    #+#             */
/*   Updated: 2019/08/30 12:14:15 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	appel(int a, int b)
{
	int c;
	int d;
	int e;
	int f;

	c = a / 10 + 48;
	d = a % 10 + 48;
	e = b / 10 + 48;
	f = b % 10 + 48;
	write(1, &c, 1);
	write(1, &d, 1);
	write(1, " ", 1);
	write(1, &e, 1);
	write(1, &f, 1);
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			appel(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
