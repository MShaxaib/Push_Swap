NAME = push_swap
BONUS_NAME = checker
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
RM			=	rm -rf


#FILES AND PATH
HEADER_SRCS	=	push_swap.h
HEADER_DIR	=	src/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	push_swap.c  Parsing.c ps_getcharlist.c push_swap_utils.c mech_turk.c mech_turk_utils.c sort.c
MPATH_DIR	=	src/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS  =	init_stack.c push_moves.c stack_ops.c stack_utils.c destroy_stk.c rotate_moves.c
BPATH_DIR	=	stacks/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS)) 
OBJ_B		=	$(BPATH:.c=.o)

GNLPATH_SRCS  =	get_next_line.c get_next_line_utils.c
GNLPATH_DIR	=	GetNextLine/
GNLPATH		=	$(addprefix $(GNLPATH_DIR), $(GNLPATH_SRCS)) 
OBJ_GNL		=	$(GNLPATH:.c=.o)

FUNC_SRCS	=	ft_split.c ft_substr.c ft_strlen.c ft_isnum.c ft_join.c ft_atol.c ft_strcmp.c
FUNC_DIR	=	Utils/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

BONUS_SRCS	=	main.c
BONUS_DIR	=	checker_code/
BONUS 		=	$(addprefix $(BONUS_DIR), $(BONUS_SRCS))
OBJ_BONUS	=	$(BONUS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra
#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_F) $(OBJ_M) $(OBJ_B)
				@$(CC) $(CFLAGS) src/main.c -c -o src/main.o
				@$(CC) ${CFLAGS} $(OBJ_F) $(OBJ_M) $(OBJ_B) src/main.o -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@$(RM) $(OBJ_B)
				@$(RM) $(OBJ_BONUS)
				@$(RM) $(OBJ_GNL)
				@$(RM) src/main.o
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME) $(BONUS_NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

bonus:			$(OBJ_F) $(OBJ_M) $(OBJ_B) $(OBJ_GNL) $(OBJ_BONUS)
				@$(CC) ${CFLAGS} $(OBJ_F) $(OBJ_M) $(OBJ_B) $(OBJ_GNL) $(OBJ_BONUS) -o checker
				@echo "$(PINK)$(BONUS_NAME) with bonus created!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
PINK 	= \033[1;45m
DEFAULT = \033[0m