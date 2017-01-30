/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:31:07 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 15:45:14 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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

int		main(int argc, char **argv)
{
	int		size;
	char	*array;

	(void)argc;
	size = find_size(argv[1]);
	array = set_array(argv[1], size);
	ft_putstr(array);
	return (0);
}
