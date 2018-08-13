# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/08/13 09:05:54 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	push_swap

INCLUDES= -I ./libft_gnl/includes

all:	$(NAME1)

lib: 
	make re -C ./libft_gnl/


SRC= 



OBJ2=	$(SRC:.c=.o)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)


re:	fclean all
