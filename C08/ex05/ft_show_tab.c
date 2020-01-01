/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 01:26:26 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/19 17:42:36 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ex04/ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *str);
int					ft_strlen(char *str);

void				ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, &*str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void				ft_putnbr(int nb)
{
	unsigned int	n;
	int				a;

	n = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * -1;
	}
	if (n < 10)
	{
		a = n + 48;
		write(1, &a, 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	write(1, "\n", 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (par[i].str[j])
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
		i++;
	}
}
