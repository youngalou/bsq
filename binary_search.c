/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:22:57 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 22:20:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		binary_search(int *arr, int l, int r, int x)
{
	int m;

	if (r >= l)
	{
		m = l + (r - l) / 2;
		if (arr[m] == x)
			return (m);
		else if (arr[m] > x)
			return (binary_search(arr, l, mid - 1, x));
		else
			return (binary_search(arr, mid + 1, r, x));
	}
	return (-1);
}
