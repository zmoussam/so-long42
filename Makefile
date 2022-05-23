# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 19:51:56 by zmoussam          #+#    #+#              #
#    Updated: 2022/05/23 20:50:06 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
SRC = ./mandatory/so_long.c\
			./mandatory/check_error.c\
			./mandatory/about_map.c\
			./mandatory/utils_map.c\
			./mandatory/handel_moves.c\
			./mandatory/handel2_moves.c\
			./mandatory/put_to_window.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\
			./printf/ft_printf.c\
			./printf/ft_ft.c\
			./printf/ft_ft2.c\
			./printf/ft_put_all_number.c
BNS_SRC = ./bonus/so_long.c\
			./bonus/check_error.c\
			./bonus/about_map.c\
			./bonus/utils_map.c\
			./bonus/handel_moves.c\
			./bonus/handel2_moves.c\
			./bonus/put_to_window.c\
			./bonus/handel_enemie_moves.c\
			./bonus/moves_enemie.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\
			./printf/ft_printf.c\
			./printf/ft_ft.c\
			./printf/ft_ft2.c\
			./printf/ft_put_all_number.c
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -g -Wall -Wextra -Werror
FFLAGS = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJS) ./mandatory/so_long.h ./get_next_line/get_next_line.h ./printf/ft_printf.h
	@$(CC) $(CFLAGS) $(FFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME) ./bonus/so_long_bonus.h ./get_next_line/get_next_line.h ./printf/ft_printf.h

$(BONUS_NAME) : $(BOBJ)
	@$(CC) $(CFLAGS) $(FFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all