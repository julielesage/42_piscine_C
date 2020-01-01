# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlesage <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/19 17:18:42 by jlesage           #+#    #+#              #
#    Updated: 2019/09/19 23:10:05 by jlesage          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= $(addprefix $(PATHSRCS), \
		ft_putchar.c \
		ft_swap.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_strcmp.c )

OBJS	= ${SRCS:.c=.o}

PATHINC = includes/

HEADERS = ft.h

PATHSRCS= srcs/

all: 		$(NAME)

$(NAME):	$(OBJS) $(addprefix $(PATHINC), $(HEADERS))
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
			gcc -o $@ -c $< $(FLAGS) -I $(PATHINC)

clean    :
	       	rm -rf $(OBJS)

fclean    : clean
	       	rm -rf $(NAME)

re        : fclean all

.PHONY    : all clean fclean re
