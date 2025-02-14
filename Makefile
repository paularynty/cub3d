# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 14:38:26 by prynty            #+#    #+#              #
#    Updated: 2025/02/12 16:37:06 by prynty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET 			= \033[0;39m
BLACK			= \033[1;30m
DARK_RED		= \033[1;31m
DARK_GREEN		= \033[1;32m
DARK_YELLOW		= \033[1;33m
DARK_BLUE		= \033[1;34m
DARK_MAGENTA	= \033[1;35m
DARK_CYAN		= \033[1;36m
DARK_GRAY		= \033[0;90m
LIGHT_GRAY		= \033[1;37m
RED				= \033[1;91m
ORANGE 			= \e[1m\e[38;5;202m
YELLOW 			= \033[0;93m
YELLOW_BOLD		= \033[1;93m
GREEN			= \033[1;92m
BLUE 			= \033[0;94m
BLUE_BOLD 		= \033[1;94m
CYAN 			= \033[0;96m
CYAN_BOLD 		= \033[1;96m
MAGENTA 		= \033[1;95m
PINK			= \e[1m\e[38;5;212m
WHITE 			= \033[1;97m

OBJ_READY		= echo "📥 $(ORANGE)Compiled Philosophers files!$(RESET)"
PHILO_READY		= echo "🧮 $(GREEN)Philosophers ready! Run the program with ./philo [args]$(RESET)"
CLEANING		= echo "💧 $(CYAN)Cleaning...$(RESET)"
CLEANED			= echo "💧 $(CYAN_BOLD)Successfully cleaned all object files!$(RESET)"
FCLEANING		= echo "🧼 $(BLUE)Deep cleaning...$(RESET)"
FCLEANED		= echo "🧼 $(BLUE_BOLD)Successfully cleaned all executable files!$(RESET)"
REMAKE			= echo "✅ $(GREEN)Successfully cleaned and rebuilt everything!$(RESET)"

NAME			= philo

SRCDIR			= srcs
OBJDIR			= objs
INCLUDE			= include
HEADER			= $(INCLUDE)/philo.h

CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDE)

SRCS			= $(SRCDIR)/main.c \
				$(SRCDIR)/forks.c \
				$(SRCDIR)/cleanup.c \
				$(SRCDIR)/init.c \
				$(SRCDIR)/routine.c \
				$(SRCDIR)/threads.c \
				$(SRCDIR)/utils.c

OBJS			= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@cc -pthread $(CFLAGS) $(SRCS) -o $(NAME)
	@$(OBJ_READY)
	@chmod 777 $(NAME)
	@$(PHILO_READY)

clean:
	@$(CLEANING)
	@rm -rf $(OBJS)
	@rm -rf objs/
	@$(CLEANED)

fclean: clean
	@$(FCLEANING)
	@rm -rf $(NAME)
	@$(FCLEANED)

re:	fclean all
	@$(REMAKE)

.PHONY: all clean fclean re
