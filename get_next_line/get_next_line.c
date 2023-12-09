/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:07:51 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/08 14:04:18 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*new;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	new = ft_calloc(sizeof(char), i + 2);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		new[i++] = '\n';
	return (new);
}

char	*ft_next(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (save[i])
		line[j++] = save[i++];
	free(save);
	return (line);
}

char	*read_file(int fd, char *save)
{
	int				bytes_read;
	char			*buffer;

	if (!save)
		save = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		save = ft_free(save, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	save = read_file(fd, save);
	if (save == NULL)
		return (NULL);
	line = ft_get_line(save);
	save = ft_next(save);
	return (line);
}

// #include <stdio.h>
// #include <unistd.h>
// int main(int argc, char **argv)
// {
// 	int	file;
// 	char	*temp;
// 	(void)argc;
// 	(void)argv;
// 	file = open(argv[1], O_RDWR);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	temp = get_next_line(file);
// 	printf("%s\n", temp);
// 	close(file);
// }