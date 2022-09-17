# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/16 22:34:50 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers

INCLUDE	=	-I./includes

RM		=	rm -rf
CC		=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-pthread

SOURCS		=	routine.c new_thread.c
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SOURCS))
OBJS_DIR	=	objects

VPATH		=	. ./sourcs

$(OBJS_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c  $< -o $@ $(INCLUDE)

################################################################################
# MANDATORY
################################################################################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					make libft
					ar -rcs lib $(OBJS)
#					$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR):
					mkdir -p $@

################################################################################
# MANDATORY	LIBFT
################################################################################

libft		=	./libft/libft.a

libft:
					$(MAKE) -C ./libft

################################################################################
# MANDATORY	RULES
################################################################################

clean:
					$(MAKE) -C ./libft clean
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(libft)
					$(RM) $(NAME)
					$(RM) lib

re:					fclean all

################################################################################
# TEST
################################################################################

TST	=	exec_tst


run_tst:
					$(CC) $(CFLAGS)  -pthread ./test/thereads_tst.c lib -o $(TST)
					./$(TST)
clear_tst:
					@$(RM) $(TST)

test:				$(NAME) run_tst clear_tst

.PHONY: 			all libft clean fclean re test
