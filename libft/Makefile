# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsoporan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/22 19:28:24 by dsoporan          #+#    #+#              #
#    Updated: 2017/02/28 14:01:50 by dsoporan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SHARED = libft.so

SRCS =	ft_isalnum.c ft_isprint.c ft_memchr.c ft_memmove.c ft_putendl.c\
ft_putstr.c ft_strclr.c ft_strdup.c ft_strjoin.c ft_strmapi.c\
ft_strnequ.c ft_strstr.c ft_toupper.c ft_isalpha.c ft_itoa.c\
ft_memcmp.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strcmp.c\
ft_strequ.c ft_strlcat.c ft_strncat.c	ft_strnew.c ft_strsub.c\
ft_atoi.c ft_isascii.c	ft_memalloc.c ft_memcpy.c ft_putchar.c\
ft_putnbr.c ft_strcat.c ft_strcpy.c ft_striter.c ft_strlen.c\
ft_strncmp.c ft_strnstr.c ft_strtrim.c\
ft_bzero.c ft_isdigit.c ft_memccpy.c ft_memdel.c ft_putchar_fd.c\
ft_putnbr_fd.c ft_strchr.c ft_strdel.c ft_striteri.c ft_strmap.c\
ft_strncpy.c ft_strrchr.c ft_tolower.c ft_lstnew.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_lstiter.c ft_strsplit.c

OBJ =  $(SRC:.c=.o)

all :
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean :
	@/bin/rm -f *.o

fclean : clean
	@/bin/rm -f $(NAME) $(SHARED)

re : fclean all
