########################################
########## VARIABLES

NAME		= so_long
CC			= gcc
INCLUDES	= includes
CFLAGS		= -Wall -Werror -Wextra -I
FT_PRINTF	= ft_printf
LIBFT		= libft
MINILIBX	= minilibx-linux
RM			= rm -f
SRCS_DIR	= srcs/

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
SRCS_FILES	= main so_long ft_display \
			get_map utils check_map_1 check_map_2 check_map_path \
			ft_free handle_move
SRCS 		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		= $(SRCS:.c=.o)

.c.o:
		@echo "$(MAGENTA)Compilation of : $<..$(DEF_COLOR)"
		@$(CC) $(CFLAGS) $(INCLUDES) -g3 -lm -c $< -o $(<:.c=.o)

########################################
########## RULES

all:		$(NAME)

$(NAME):	$(OBJS)
				@make -C $(FT_PRINTF)
				@make -C $(LIBFT)
				@make -C $(MINILIBX)
				@$(CC) $(OBJS) ft_printf/libftprintf.a libft/libft.a $(MINILIBX)/libmlx_Linux.a -lXext -lX11 -o $(NAME)
				@echo "$(GREEN)So_long successfully compiled !$(DEF_COLOR)"

clean:
				$(RM) $(OBJS)
				@make clean -C $(FT_PRINTF)
				@make clean -C $(LIBFT)
				@make clean -C $(MINILIBX)
				@echo "$(RED)Deletion of $(OBJS)$(DEF_COLOR)"

fclean: 	clean
				@$(RM) $(NAME)
				@$(RM) ft_printf/libftprintf.a
				@$(RM) libft/libft.a
				@$(RM) $(MINILIBX)/libmlx_Linux.a
				@echo "$(RED)Deletion of $(NAME)$(DEF_COLOR)"

re:			fclean all

norm:
			norminette $(SRCS) $(INCLUDES) $(FT_PRINTF) $(LIBFT) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
