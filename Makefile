# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/15 14:53:42 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers

INCLUDE	=	-I./includes

CC		=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM		=	rm -rf

SOURCS		=	main.c
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SOURCS))
OBJS_DIR	=	objects

VPATH		=	. ./sourcs

$(OBJS_DIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

################################################################################
# MANDATORY
################################################################################

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					make libft
					ar -rcs $@ $(OBJS)

$(OBJS_DIR):
					mkdir -p $@

################################################################################
# MANDATORY	RULES
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

re:					fclean all

.PHONY: 			all libft clean fclean re
