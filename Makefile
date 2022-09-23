# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 17:42:21 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/23 09:27:57 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	philo

LIBFT	=	./libft/libft.a
INCLUDE	=	-I./includes

RM		=	rm -rf
CC		=	gcc
#CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	=	-pthread

SOURCS		=	routine.c new_thread.c valid_argv.c creat_table.c philo_eat.c \
				start_thread.c
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

LIBS		=	lib $(LIBFT)
FILE		=	./test/$(t).c
FILES		=	$(wildcard ./test/*.c)

EXEC		=	$(patsubst %.c, %.out, $(FILE))
EXECS		=	$(patsubst %.c, %.out, $(FILES))

test:		$(NAME) $(EXEC)

tests:		$(NAME)	$(EXECS)

################################################################################
# VG TEST
################################################################################

LIBS		=	lib $(LIBFT)
VGFILE		=	./test/$(t).vg.out
VGFILES		=	$(wildcard ./test/*.c)

VGEXEC		=	$(patsubst %.c, %.vg.out, $(VGFILE))
VGEXECS		=	$(patsubst %.c, %.vg.out, $(VGFILES))

vgtest:		$(NAME) $(VGEXEC)

vgtests:	$(NAME)	$(VGEXECS)


################################################################################
# .OUT
################################################################################

%.out:		%.c
				$(CC) $(CFLAGS) $< $(LIBS) -o $@ $(INCLUDE)
				@$@
				@$(RM) $@

%.vg.out: 	%.c
				$(CC) $(CFLAGS) $< $(LIBS) -o $@ $(INCLUDE)
				@valgrind $@
				@$(RM) $@

.PHONY: 			all libft clean fclean re test
