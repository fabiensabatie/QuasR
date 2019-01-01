# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2018/02/15 20:36:30 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Defining variables

NAME = libft.a

#Paths

INCLUDES_PATH = ../includes
IO_PATH = ../io_functions
LIST_PATH = ../list_functions
MATH_PATH = ../math_functions
MEM_PATH = ../memory_functions
STR_PATH =  ../string_functions
OBJ_PATH = ./build

#Sources files

IO_SRC =	buffer.c ft_printf.c ft_putendl.c ft_putnbr_fd.c ft_putwchar.c get_next_line.c \
			spec_handlers.c ft_atoi.c ft_putchar.c ft_putendl_fd.c ft_putstr.c ft_putwstr.c \
			handlers.c str_printers.c ft_itoa.c ft_putchar_fd.c ft_putnbr.c ft_putstr_fd.c \
			ft_retsplit.c nb_printers.c

LIST_SRC =	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c

MATH_SRC =	ft_abs.c ft_equa.c ft_vec.c

MEM_SRC =	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
			ft_memmove.c ft_memset.c

STR_SRC =	ft_chartostr.c ft_isprint.c ft_strcpy.c ft_strjoin.c ft_strncat.c ft_strrchr.c \
			ft_tolower.c ft_chrcstr.c ft_strcat.c ft_strcsub.c ft_strjoin_char.c ft_strncmp.c \
			ft_strrev.c ft_toupper.c ft_chrstr.c ft_strchr.c ft_strdel.c ft_strjoinfree.c \
			ft_strncpy.c ft_strrpos.c ft_wstrlen.c ft_isalnum.c ft_strclr.c ft_strdup.c \
			ft_strlcat.c ft_strnequ.c ft_strsplit.c ft_wstrnsub.c ft_isalpha.c ft_strcmp.c \
			ft_strequ.c ft_strlen.c ft_strnew.c ft_strstr.c ft_isascii.c ft_strcount.c ft_striter.c \
			ft_strmap.c ft_strnstr.c ft_strsub.c ft_isdigit.c ft_strcpos.c ft_striteri.c \
			ft_strmapi.c ft_strnsub.c ft_strtrim.c

# Prefixing source files with respective paths

IO = $(addprefix $(IO_PATH)/,$(IO_SRC))
LIST = $(addprefix $(LIST_PATH)/,$(LIST_SRC))
MATH = $(addprefix $(MATH_PATH)/,$(MATH_SRC))
MEM = $(addprefix $(MEM_PATH)/,$(MEM_SRC))
STR = $(addprefix $(STR_PATH)/,$(STR_SRC))

# Defining build paths and variables

SOURCES = $(IO) $(LIST) $(MATH) $(MEM) $(STR)
SRCS_LIST = $(IO_SRC) $(LIST_SRC) $(MATH_SRC) $(MEM_SRC) $(STR_SRC)
OBJS_LIST = $(SRCS_LIST:.c=.o)
BUILD_OBJ = $(addprefix $(OBJ_PATH)/,$(OBJS_LIST))

# Compilation flags

CC = gcc
CPPFLAGS = -Wall -Wextra -Werror
INCLUDES = -I $(INCLUDES_PATH)

# Definign rules

all: $(NAME)

$(NAME):
	@mkdir $(OBJ_PATH) && cd $(OBJ_PATH) && $(CC) $(CPPFLAGS) $(INCLUDES) -c $(SOURCES)
	@ar rc $(NAME) $(BUILD_OBJ)
	@ranlib $(NAME)
	@echo "Compiled libft."

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all