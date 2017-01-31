/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:52:29 by jle-quel          #+#    #+#             */
/*   Updated: 2017/01/30 22:15:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_putchar(char c);
void	ft_putstr(char *str);
int		find_size(char *file);
int		key_length(char *file);
int		find_height(char *file);
int		find_width(char *file, int size, int height);
char	*set_array(char *file, int size);
char	**set_matrix(int height, int width);
char	**fill_matrix(char **matrix, char *array);
int		binary_search(int *arr, int l, int r, int x);

#endif
