# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 12:59:34 by bepoisso          #+#    #+#              #
#    Updated: 2025/05/14 15:18:16 by bepoisso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Fight
CXX= c++ -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
