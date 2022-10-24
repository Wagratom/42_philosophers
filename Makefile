# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 15:47:23 by wwallas-          #+#    #+#              #
#    Updated: 2022/10/24 11:52:34 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
LIB_FILO	=	philo.a

MAIN		=	./source/main.c

INCLUDE		=	-I./include

SOURCE	=	valid_argv.c create_table.c create_philo.c control_time.c          \
			init_thread.c routine.c eating.c guardian.c destroy_table.c        \
			one_philo.c print_protect.c ft_atoi.c ft_calloc.c ft_itoa.c        \
			ft_putstr.c ft_str_eq.c ft_strlen.c verify_int.c ft_numb_house.c   \
			ft_strdup.c \

OBJECTS		=	$(patsubst %.c, $(OBJECTS_DIR)/%.o, $(SOURCE))
OBJECTS_DIR	=	objects

CC 		=	gcc -g3
#-fsanitize=thread
CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

VPATH	=	./source                \
			./source/ults           \
			./source/table          \
			./source/start_program

$(OBJECTS_DIR)/%.o:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all:	$(NAME)

$(NAME):	$(OBJECTS_DIR) $(OBJECTS)
				ar -rcs $(LIB_FILO) $(OBJECTS)
				$(CC) $(CFLAGS) $(MAIN) $(LIB_FILO) -o $@ $(INCLUDE)

$(OBJECTS_DIR):
				mkdir -p $@

clean:
				$(MAKE) -C ./libft clean
				$(RM) $(OBJECTS_DIR)

fclean:		clean
				$(RM) $(NAME)
				$(RM) $(LIB_FILO)
				$(MAKE) -C ./libft fclean

re: fclean all

################################################################################
#									TEST
################################################################################

TST_PATH		=	./test

AUXILIARES		=	$(wildcard ./test/ults/*.c)

FILE_TST		=	$(TST_PATH)/$(t).c
OJBS_TST		=	$(patsubst %.c, %.out, $(FILE_TST))

FILE_TSTS		=	$(wildcard $(TST_PATH)/**/*.c);
OJBS_TSTS		=	$(patsubst %.c, %.out, $(FILE_TSTS))

%.out:	%.c
		@$(CC) $< $(AUXILIARES) $(LIB_FILO) -o $@ $(INCLUDE)
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

VG_FILE_TSTS		=	$(wildcard $(TST_PATH)/**/*.c)
VG_OJBS_TSTS		=	$(patsubst %.c, %.vg.out, $(VG_FILE_TSTS))

%.vg.out:	%.c
		@$(CC) $< $(AUXILIARES) $(LIB_FILO) -o $@
		valgrind --leak-check=full ./$@
		@$(RM) $@

vgtest: re_mandatory $(VG_OJBS_TST)

vgtests: re_mandatory $(VG_OJBS_TSTS)

re_mandatory:
		$(RM) $(OBJECTS_DIR)
		make

.PHONY: all clean fclean re
