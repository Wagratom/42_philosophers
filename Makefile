# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/14 18:41:08 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCS		=	main.c

OBJS_DIR	=	objects
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SOURCS))

CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror

libft		=	./libft/libft.a

NAME		=	philosophers


$(OBJS_DIR)/%.o:	%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					make libft
					ar -rcs $@ $(OBJS)

$(OBJS_DIR):
						mkdir -p $@

libft:
					$(MAKE) -C ./libft

clean:
					$(MAKE) -C ./libft clean

fclean:				clean
					$(RM) $(libft)

re:					fclean all

.PHONY: 			all libft clean fclean re
