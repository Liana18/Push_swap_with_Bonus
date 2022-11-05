NAME		= push_swap
NAME_BONUS	= checker
SRC			= $(wildcard src/*/*.c)
SRC			+= $(wildcard src/*.c)
SRC_BONUS	= $(wildcard src_bonus/*/*.c)
SRC_BONUS	+= $(wildcard src_bonus/*.c)
OBJS		= $(SRC:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)
INCLUDES	= ./includes 
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
CC			= cc

%.o:%.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(NAME) $(NAME_BONUS)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS)
		$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS_BONUS) -o $(NAME_BONUS)

clean	:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean	: 	clean
			$(RM) $(NAME) $(NAME_BONUS) 
			rm -rf ~/LIbrary/Caches

re		:fclean all
.PHONY: all clean fclean re
