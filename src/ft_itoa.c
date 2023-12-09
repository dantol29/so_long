/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:35:38 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/08 19:19:18 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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
