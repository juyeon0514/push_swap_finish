# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 17:18:52 by juykang           #+#    #+#              #
#    Updated: 2022/11/05 14:35:07 by juykang          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

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

BONUS_FILE = checker				\
			 checker_main			\
			 array_bonus			\
			 array_utils_bonus		\
			 ft_split_bonus			\
			 ft_split_utils_bonus	\
			 get_next_line_ps		\
			 get_next_line_utils_ps	\
			 push_swap_command_bonus\
			 push_swap_reverse_rotate_bonus\
			 push_swap_rotate_bonus \

ifdef MAKE_CHECKER
	TARGET = $(CHECKER)
else
	TARGET = $(NAME)
endif

		 
OBJ_DIR = objects
OBJ_DIR_BONUS = objects2
OBJCS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
OUT_DIR = checker_file
OBJCS_CHECKER = $(addprefix checker_file/$(OBJ_DIR_BONUS)/, $(addsuffix .o, checker_file/$(BONUS_FILE)))
INC = push_swap.h
INC_BONUS = checker_file/checker.h


.PHONY : all clean fclean re bonus

all : 
	@make $(TARGET)

$(NAME) : $(OBJCS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o : %.c $(INC)
	@mkdir -p $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(CHECKER) : $(OBJCS_CHECKER)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR_BONUS)/%.o : %.c $(INC_BONUS)
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR_BONUS)
	$(RM) $(RMFLAGS) $(OBJ_DIR)

bonus:
	@make MAKE_CHECKER=1 all

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(CHECKER)

re :
	make fclean
	make all

