NAME	=	get_next_line.a
FLAGS	=	-Wall -Wextra -Werror

SRCS = 	get_next_line_utils.c	\
		get_next_line.c			\

OBJS = $(SRCS:.c=.o)

SRCSBONUS =	

OBJSBONUS = $(SRCSBONUS:.c=.o)

.PHONY: all clean fclean re bonus

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus:	$(OBJSBONUS)
		ar rc $(NAME) $(OBJSBONUS)
		ranlib $(NAME)

.c.o:
		gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		rm -rf $(OBJS) $(OBJSBONUS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all
