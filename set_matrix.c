/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:31:07 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 16:37:56 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		find_size(char *file)
{
	int		fd;
	int		size;
	char	*buff;

	size = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, &buff, 1))
		size++;
	return (size);
}

int		key_length(char *file)
{
	int		len;
	int		fd;
	char	buff[1];

	len = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, buff, 1) && buff[0] != '\n')
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

int		find_width(char *file, int size, int height)
{
	int		width;

	width = (size - key_length(file) - height) / height;
	return (width);
}

char	*set_array(char *file, int size)
{
	int		i;
	int		fd;
	char	buff[1];
	char	*array;

	i = 0;
	array = (char*)malloc(size * sizeof(array));
	fd = open(file, O_RDONLY, S_IRUSR);
	while (read(fd, buff, 1))
	{
		array[i] = buff[0];
		i++;
	}
	return (array);
}

char	**set_matrix(int height, int width)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = (char**)malloc(height * sizeof(matrix));
	while (i < height)
	{
		matrix[i] = (char*)malloc(width * sizeof(matrix));
		i++;
	}
	return (matrix);
}

char	**fill_matrix(char **matrix, char *array)
{
	int		i;
	int		y;
	int		x;

	i = 0;
	y = 0;
	x = 0;
	while (array[i] != '\n')
		i++;
	i++;
	while (array[i])
	{
		if (array[i] != '\n')
		{
			matrix[y][x] = array[i];
			x++;
		}
		else
		{
			y++;
			x = 0;
		}
		i++;
	}
	return (matrix);
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	int		height;
	int		width;
	char	*array;
	char	**matrix;

	(void)argc;
	i = 0;
	size = find_size(argv[1]);
	array = set_array(argv[1], size);
	height = find_height(argv[1]);
	width = find_width(argv[1], size, height);
	matrix = set_matrix(height, width);
	matrix = fill_matrix(matrix, array);
	printf("height = %d\nwidth = %d\n", height, width);
	while (i < height)
	{
		ft_putstr(matrix[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(array);
	return (0);
}
