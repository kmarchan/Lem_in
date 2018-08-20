# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmarchan <kmarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 13:53:38 by kmarchan          #+#    #+#              #
#    Updated: 2018/08/20 15:54:35 by kmarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	lem-in

INCLUDES= -I ./libft_gnl/includes

all:	$(NAME)

lib: 
	make re -C ./libft_gnl/
	make clean -C ./libft_gnl/


SRC= lem_in.c read_file.c memory_man.c get_ants.c get_rooms.c ft_list.c vector.c \
	get_links.c get_path.c move_ants.c



OBJ=	$(SRC:.c=.o)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) $(INCLUDES)
	gcc -o $(NAME) $(OBJ) $(INCLUDES) -L. ./libft_gnl/libft.a

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)


re:	fclean all
