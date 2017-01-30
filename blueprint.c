/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 10:27:53 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 14:42:54 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	/* 1. Open and read file
	 * 		a. fd = open() & read(fd, &buff, 1)
	 * 		b. confirm file is in valid format
	 * 			- all lines must have same length
	 * 			- at least one line of at least one box
	 * 			- line break at the end of each line
	 * 		c. if map is invalid, display "map error" on error output (2) followed by line break.
	 * 			- program then moves onto next map
	 * 		d. analyze first line (# of lines, "empty" char, "obstacle" char, "full" char)
	 * 2. Set **matrix
	 * 		a. creat a 2D matrix (using malloc so you can return a pointer to the matrix), containing values for empty and obstacle chars.
	 * 		b. go through all rows and columns and set up arrays containing positions of obstacles for each of them
	 * 3. Check every possible square in the matrix
	 * 		a. starting at top-left corner, see if 1x1 square is feasible
	 * 		b. if it works, increase side lengths of the square by one and repeat
	 * 			- when increasing square size, use binary search to see if next row/column contain any obstacles
	 * 			- when moving right, binary search next column to check for obstacles
	 * 			- when moving down, binar search next row to check for obstaclese
	 * 		c. if it doesn't work, move right and repeat. if you've reached the right-most position, move to next line.
	 * 4. 
}
