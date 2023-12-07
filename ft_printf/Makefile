########################################
########## ARGUMENTS

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I ../includes
AR			= ar -crs
SRCS_DIR	= srcs/
RM			= rm -f

########################################
########## COLORS
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

########################################
########## SOURCES
SRCS_FILES	= ft_printf ft_putchar ft_puthexa \
			ft_putnbr ft_putptr ft_putstr ft_putunsigned
SRCS 		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))

OBJS		= ${SRCS:.c=.o}

.c.o:
		@echo "$(CYAN)Compilation of : $<..$(DEF_COLOR)"
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

########################################
########## RULES

all: $(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)Ft_printf successfully compiled !$(DEF_COLOR)"

clean:
		@$(RM) $(OBJS)
		@echo "$(RED)Deletion of $(OBJS)$(DEF_COLOR)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(RED)Deletion of $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
