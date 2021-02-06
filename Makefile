# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: anspirga <anspirga@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/24 18:34:34 by anspirga      #+#    #+#                  #
#    Updated: 2021/01/30 17:55:12 by anspirga      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = c_print.c find_specifier.c ft_my_itoa.c ft_printf.c replace_star.c\
 		s_print.c print_iduxxp.c utilities_print_iduxxp.c\
  		utilities_print.c utilities.c

OBJ_FILES = $(SRCS:.c=.o)
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
