# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 11:43:35 by dmodrzej          #+#    #+#              #
#    Updated: 2024/05/03 22:49:44 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	client

NAME_S	=	server

SRCS_C	=	client.c

SRCS_S	=	server.c

OBJS_C	=	$(SRCS_C:.c=.o)

OBJS_S	=	$(SRCS_S:.c=.o)

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

# COLORS & SYMBOLS
GREEN 	= 	\033[0;32m
CYAN	=	\033[0;36m
NC		= 	\033[0m
TICK	=	✅

define PRINT_LOADING
	@printf "$(CYAN)["
	@for i in $$(seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef

%.o: %.c
			@$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME_C) $(NAME_S)

$(NAME_C):	$(OBJS_C)
			@echo "$(CYAN)Compiling libft...$(NC)"
			@$(PRINT_LOADING)
			@make -s -C libft
			@echo "$(GREEN)Libft compilation successful		$(TICK)$(NC)"
			@echo "$(CYAN)Compiling ft_printf...$(NC)"
			@$(PRINT_LOADING)
			@make -s -C ft_printf
			@echo "$(GREEN)Ft_printf compilation successful	$(TICK)$(NC)"
			@echo "$(CYAN)Compiling client program...$(NC)"
			@$(PRINT_LOADING)
			@$(CC) $(FLAGS) $(OBJS_C) -o $@ -L libft -lft -L ft_printf -lftprintf
			@echo "$(GREEN)Client program compilation successful	$(TICK)$(NC)"

$(NAME_S):	$(OBJS_S)
			@echo "$(CYAN)Compiling server program...$(NC)"
			@$(PRINT_LOADING)
			@$(CC) $(FLAGS) $(OBJS_S) -o $@ -L libft -lft -L ft_printf -lftprintf
			@echo "$(GREEN)Server program compilation successful	$(TICK)$(NC)"

clean:		
			@echo "$(CYAN)Cleaning .o files...$(NC)"
			@$(PRINT_LOADING)
			@make -s -C libft clean
			@make -s -C ft_printf clean
			@rm -f $(OBJS_C) $(OBJS_S)
			@echo "$(GREEN)Cleaning of .o files successful		$(TICK)$(NC)"

fclean:		clean
			@echo "$(CYAN)Cleaning everything else...$(NC)"
			@$(PRINT_LOADING)
			@make -s -C libft fclean
			@make -s -C ft_printf fclean
			@rm -f $(NAME_C) $(NAME_S)
			@echo "$(GREEN)Full cleaning successful		$(TICK)$(NC)"

re:			fclean all

.PHONY:		all clean fclean re