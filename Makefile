# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 15:47:23 by wwallas-          #+#    #+#              #
#    Updated: 2022/10/03 16:55:37 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo
LIBFT	=	libft/libft.a

INCLUDE	=	-I./include

SOURCE	=	valid_argv.c creat_table.c creat_forks.c creat_philo.c             \
			creat_thread.c control_time.c init_thread.c destroy_table.c        \
			init_philo.c

OBJECTS		=	$(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SOURCE))
OBJECTS_DIR	=	objects

CC 		=	gcc -g3
CFLAGS	=	#-Wall -Wextra -Werror

RM		=	rm -rf

VPATH	=	. ./source ./source/struct ./source/start_program

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

################################################################################
#									TESTVG
################################################################################

TST_PATH		=	./test

VG_FILE_TST		=	$(TST_PATH)/$(t).c
VG_OJBS_TST		=	$(patsubst %.c, %.vg.out, $(VG_FILE_TST))

VG_FILE_TSTS		=	$(wildcard $(TST_PATH)/*.c);
VG_OJBS_TSTS		=	$(patsubst %.c, %.vg.out, $(VG_FILE_TSTS))

%.vg.out:	%.c
		@$(CC) $< $(NAME) $(LIBFT) -o $@
		valgrind --leak-check=full ./$@
		@$(RM) $@

vgtest: re_mandatory $(VG_OJBS_TST)

vgtests: re_mandatory $(VG_OJBS_TSTS)

re_mandatory:
		$(RM) $(OBJECTS_DIR)
		make

.PHONY: all clean fclean re
