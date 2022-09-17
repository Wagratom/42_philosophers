# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/17 18:36:26 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philosophers

LIBFT	=	./libft/libft.a
INCLUDE	=	-I./includes

RM		=	rm -rf
CC		=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-pthread

SOURCS		=	routine.c new_thread.c ft_is_array_int.c
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

LIBS			=	lib $(LIBFT)
TST	=			exec_tst

THREADS	=		./test/thereads_tst.c
IS_ARRAY	= 	./test/new_func_lib.c

clear_tst:
					@$(RM) $(TST)


thereads:			$(NAME)
						$(CC) $(CFLAGS) $(THREADS) $(LIBS) -o $(TST)
						./$(TST)
						MAKE clear_tst

new_func_lib:	$(NAME)
					$(CC) $(CFLAGS) $(IS_ARRAY) $(LIBS) -o $(TST)
						./$(TST)
						MAKE clear_tst

.PHONY: 			all libft clean fclean re test
