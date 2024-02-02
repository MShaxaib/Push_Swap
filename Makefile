NAME = push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g3
RM			=	rm -rf


#FILES AND PATH
HEADER_SRCS	=	push_swap.h
HEADER_DIR	=	src/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	push_swap.c main.c Parsing.c ps_getcharlist.c push_swap_utils.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS  =	init_stack.c stack_moves.c stack_ops.c
BPATH_DIR	=	stacks/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS)) 
OBJ_B		=	$(BPATH:.c=.o)

FUNC_SRCS	=	ft_split.c ft_substr.c ft_strlen.c ft_isnum.c ft_join.c ft_atol.c
FUNC_DIR	=	Utils/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address  -g3    
#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M) $(OBJ_B)
				@$(CC) ${CFLAGS} $(OBJ_F) $(OBJ_M) $(OBJ_B) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m