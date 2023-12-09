/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:35:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 14:50:02 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_playable(t_game *game)
{
	int	p;
	int	e;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	check_playable_row(game, &c, &p, &e);
	if (c == 0 || p == 0 || e == 0)
		return (1);
	return (0);
}

int	check_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (!(file[i + 1] == 'b' && file[i + 2] == 'e' \
			&& file[i + 3] == 'r' && !(file[i + 4])))
			{
				write(1, "Error\nProgramm accepts only .ber files\n", 39);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_get_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_new(int size, int off, int n, char *new)
{
	while (size > off)
	{
		new[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		off;
	int		size;
	char	*new;

	off = 0;
	size = ft_get_size(n);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		new[0] = '-';
		new[1] = '2';
		n = 147483648;
		off = 2;
	}
	if (n < 0)
	{
		new[0] = '-';
		off = 1;
		n = -n;
	}
	ft_fill_new(size, off, n, new);
	new[size] = '\0';
	return (new);
}
