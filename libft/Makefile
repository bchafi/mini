# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 22:53:59 by achnouri          #+#    #+#              #
#    Updated: 2024/11/14 23:03:01 by achnouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
ARV		=	ar -r
RM		=	rm -f

S_P1_P2	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c			\
       		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c		\
       		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c 			\
       		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c 	\
			ft_putnbr_fd.c  ft_putstr_fd.c
S_P3	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c			\
    		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

O_P1_P2	=	$(S_P1_P2:.c=.o)
O_P3	=	$(S_P3:.c=.o)

all:		$(NAME)

$(NAME):	$(O_P1_P2)
	$(ARV) $(NAME) $(O_P1_P2)

bonus:		$(O_P3)
	$(ARV) $(NAME) $(O_P3)

%.o :	%.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(O_P1_P2) $(O_P3)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all
