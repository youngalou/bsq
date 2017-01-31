/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blueprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 10:27:53 by lyoung            #+#    #+#             */
/*   Updated: 2017/01/30 17:35:03 by lyoung           ###   ########.fr       */
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
	 * 		a. create a 2D matrix (using malloc so you can return a pointer to the matrix), containing values for empty and obstacle chars.
	 * 		b. go through all rows and columns and set up arrays containing positions of obstacles for each of them
	 * 3. Check every possible square in the matrix
	 * 		a. starting at top-left corner, see if 1x1 square is feasible
	 * 		b. if it works, increase side lengths of the square by one and repeat
	 * 			- when increasing square size, use binary search to see if next row/column contain any obstacles
	 * 			- when moving right, binary search next column to check for obstacles
	 * 			- when moving down, binar search next row to check for obstaclese
	 * 		c. if it doesn't work, move right and repeat. if you've reached the right-most position, move to next line.
	 * 4. 
	 *
	 *
	 *
	 * LOGIC:
	 * - Check 1x1 cells until you find the first "empty" character.
	 * - Expand square to 2x2 and move square left until it finds a 2x2 slot with no obstacles.
	 *   If current row has no possible slots, move down 1 row, and repeat.
	 *   ~ (The cool thing about this algorithm is that you don't have to check previous slots because
	 *   	anything that has been passed over for a smaller square cannot contain the bigger square.)
	 *   ~ When we check the next row for possible squaresm make SURE to move square back to the first column.
	 * - The top-left cell in the square (first element for x and y) is going to be moved left until the end
	 *   of the square hits the right wall, then move down and repeat until the bottom of the square hits
	 *   the floor. Really, all we are moving is the top-left cell.
	 * - When we see a bigger possible square, we do NOT move the cell. We first check for a bigger sqaure
	 *   and if it isn't possible, we then move our top-left cell (and thus the entire square) through the
	 *   maze with the aformentioned search algorithm.
	 * - Continue to expand square until you find a AxA square that doesn't fit anywhere.
	 * - Print square in matrix.
}
