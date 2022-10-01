# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 15:47:23 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/30 22:41:44 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
LIBFT	=	libft/libft.a

INCLUDE	=	-I./include

SOURCE	=	valid_argv.c creat_table.c creat_forks.c creat_philo.c             \
			creat_thread.c init_thread.c

OBJECTS		=	$(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SOURCE))
OBJECTS_DIR	=	objects

CC 		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror

RM		=	rm -rf

VPATH	=	. ./source ./source/creat_struct

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

FILE_TSTS		=	$(wildcard $(TST_PATH)/*.c);
OJBS_TSTS		=	$(patsubst %.c, %.out, $(FILE_TSTS))

%.out:	%.c
		@$(CC) $< $(NAME) $(LIBFT) -o $@
		@./$@
		@$(RM) $@

test: re_mandatory $(OJBS_TST)

tests: re_mandatory $(OJBS_TSTS)


re_mandatory:
		$(RM) $(OBJECTS_DIR)
		make

.PHONY: all clean fclean re
