# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/08/13 13:41:40 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	lem-in.c

INCLUDES= -I ./libft_gnl/includes

all:	$(NAME)

lib: 
	make re -C ./libft_gnl/


SRC= lem_in.c 



OBJ=	$(SRC:.c=.o)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)


re:	fclean all
