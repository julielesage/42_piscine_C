/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlesage <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 05:20:34 by jlesage           #+#    #+#             */
/*   Updated: 2019/09/12 21:35:20 by jlesage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int j;

	j = 0;
	while (s1[j] && s2[j] && s1[j] == s2[j])
		j++;
	return (s1[j] - s2[j]);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*swap;
	int		j;

	i = 0;
	while (++i < (argc - 1))
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			swap = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = swap;
			i = 0;
		}
	}
	i = 1;
	while (i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
