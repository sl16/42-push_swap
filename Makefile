# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:14:33 by vbartos           #+#    #+#              #
#    Updated: 2023/09/20 15:09:54 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT ---------------------------------- #

NAME			= push_swap

# FLAGS ------------------------------------ #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

# SOURCE FILES ----------------------------- #

SRCS			= src/push_swap.c\
				src/arg_parser.c\
				src/arg_check.c\
				src/linked_list.c\
				src/linked_list_utils.c\
				src/stack_init.c\
				src/move_swap.c\
				src/move_push.c\
				src/move_rotate.c\
				src/move_reverse.c\
				src/algo_basic.c\
				src/algo_utils.c\
				libft/libft.a\

#SRCS_BONUS		= src_bonus/pipex.c\
				libft/libft.a\

# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# RULES ------------------------------------ #

all: $(NAME)

$(NAME):
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN) - Project compiled.$(RESET)"

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	@echo "$(GREEN) - Project binary files deleted.$(RESET)"

clean:
	${RM} ${OBJS}
	make clean -C libft
	@echo "$(GREEN) - Project object files deleted.$(RESET)"

re: fclean all

bonus: clean
	make all -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)
	@echo "$(GREEN) - Project BONUS compiled.$(RESET)"

.PHONY: all clean fclean re bonus