# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/19 12:33:37 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philo

LIBFT	=	./libft/libft.a
INCLUDE	=	-I./includes

RM		=	rm -rf
CC		=	gcc
#CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	=	-pthread

SOURCS		=	routine.c new_thread.c valid_argv.c
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
#						$(CC) $(CFLAGS) $(OBJS) -o $@

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

THREADS		=	./test/thereads_tst.c
IS_ARRAY	= 	./test/new_func_lib.c
VAL_ARGV	=	./test/valid_argv.c

clear_tst:
					@$(RM) $(TST)

thereads:		$(NAME)
						$(CC) $(CFLAGS) $(THREADS) $(LIBS) -o $(TST)
						./$(TST)
						make clear_tst

new_func_lib:	$(NAME)
						$(CC) $(CFLAGS) $(IS_ARRAY) $(LIBS) -o $(TST)
						./$(TST)
						make clear_tst

valid_argv:		$(NAME)
						$(CC) $(CFLAGS) $(VAL_ARGV) $(LIBS) -o $(TST)
						./$(TST)
						make clear_tst

tests:	thereads new_func_lib valid_argv



.PHONY: 			all libft clean fclean re test
