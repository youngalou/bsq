/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:37:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 14:20:02 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		key_length(char *file)
{
	int		len;
	int		fd;
	char	buff[1];

	len = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(1, buff, 1) && buff[0] != '\n')
		len++;
	return (len + 1);
}

int		find_height(char *file)
{
	int		height;
	int		fd;
	char	buff[1];

	height = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, buff, 1))
	{
		if (buff[0] == '\n')
			height++;
	}
	return (height - 1);
}

int		find_width(char *file, int height)
{
	int		fd;
	int		width;
	char	*buff;

	width = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, &buff, 1))
		width++;
	width = (width - key_length(file) - height) / height;
	return (width);
}

char	**set_matrix(int height, int width, char *file)
{
	int		fd;
	char	buff[1];
	int		x;
	int		y;
	int		i;
	char	**matrix;

	x = 0;
	y = 0;
	i = 0;
	matrix = (char**)malloc(height * sizeof(matrix));
	while (i < height)
	{
		matrix[i] = (char*)malloc(width * sizeof(matrix));
		i++;
	}
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, buff, 1))
	{
		if (buff[0] != '\n')
		{
			matrix[y][x] = buff[0];
			x++;
		}
		else
			y++;
	}
	return (matrix);
}

int		main(int argc, char **argv)
{
	int		height;
	int		width;
	char	**matrix;

	(void)argc;
	height = find_height(argv[1]);
	width = find_width(argv[1], height);
	matrix = set_matrix(width, height, argv[1]);
	return (0);
}
