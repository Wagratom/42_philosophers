# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 15:47:23 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/29 11:30:51 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
LIBFT	=	libft/libft.a

INCLUDE	=	-I./include
SOURCE	=	valid_argv.c

OBJECTS		=	$(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SOURCE))
OBJECTS_DIR	=	objects

CC 		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror

RM		=	rm -rf

VPATH	=	. ./source ./include

$(OBJECTS_DIR)/%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJECTS_DIR) $(OBJECTS)
				$(MAKE) -C ./libft
				ar -rcs $@ $(OBJECTS)

$(OBJECTS_DIR):
				mkdir -p $@

clean:
				$(MAKE) -C ./libft clean
				$(RM) $(OBJECTS_DIR)

fclean:
				$(RM) $(NAME)
				$(MAKE) -C ./libft fclean

re: fclean all

################################################################################
#									TEST
################################################################################

TST_PATH		=	./test
FILE_TST		=	$(TST_PATH)/$(t).c
OJBS_TST		=	$(patsubst %.c, %.out, $(FILE_TST))

%.out:	%.c
		$(CC) $< $(NAME) $(LIBFT) -o $@
		./$@
		$(RM) $@

test: re_mandatory $(OJBS_TST)

re_mandatory:
		$(RM) $(OBJECTS_DIR)
		make

.PHONY: all clean fclean re
