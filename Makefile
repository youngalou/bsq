# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 22:16:04 by jle-quel          #+#    #+#              #
#    Updated: 2017/01/30 22:22:00 by jle-quel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
FUNCTION = set_matrix.c

all:
	gcc -o bsq $(FLAG) $(FUNCTION)

clean:
	rm -f bsq

re: clean all
