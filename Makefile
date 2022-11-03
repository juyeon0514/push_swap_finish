NAME = push_swap.a

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
		push_swap_sort_5			\
		push_swap_sort_utils		\

SRCS = $(addsuffix .c, $(FILES))
OBJCS = $(addsuffix .o, $(FILES))

INC = push_swap.h

%.o : %.c $(INC)
	$(CC) -c $(CFLAGS) $< -o $@

all : mandatory_all
	@echo INC=$(INC) at the end of all

clean :
	$(RM) $(RMFLAGS) $(OBJCS) $(BONUS_OBJCS) mandatory_all

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all

mandatory_all : $(OBJCS)
	@echo INC=$(INC) during mandatory_all
	@$(RM) $(RMFLAGS) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $^
	@$(RM) $(RMFLAGS) bonus_all
	@touch $@

.PHONY : all clean fclean re bonus bonus_define
