# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:18:52 by juykang           #+#    #+#              #
#    Updated: 2022/11/03 17:19:21 by juykang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

FILES = push_swap_main				\
		array						\
		array_utils					\
		ft_split					\
		ft_split_utils				\
		push_swap_quick				\
		push_swap_quick2			\
		push_swap_command			\
		push_swap_rotate			\
		push_swap_reverse_rotate	\
		push_swap_sort				\
		push_swap_sort3_a			\
		push_swap_sort3_b			\
		push_swap_sort5				\
		push_swap_sort_utils		\

OBJ_DIR = objects
OBJCS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
INC = push_swap.h


.PHONY : all clean fclean re

all : $(NAME)
$(NAME) : $(OBJCS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

