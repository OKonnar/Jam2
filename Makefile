# ##
# ## EPITECH PROJECT, 2022
# ## B-OOP-400-STG-4-1-raytracer-alex.di-venanzio
# ## File description:
# ## Makefile
# ##

# MAKEFLAGS += -j16 -l16 -s

NAME    =   jam

SRC     =   $(shell find ./src -name "*.cpp")

OBJ     =   $(SRC:.cpp=.o)

FLAGS   =   -lconfig++ -std=c++20 -Wall -Wextra -O3 -lpthread -lstdc++fs

INCLUDE =   -I./include

SFMLINCLUDE	= -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

CFLAGS = -g

all: $(NAME) $(PLUGIN_SOS)

$(NAME): $(OBJ)
	g++ $(INCLUDE) -o $@ $^ $(FLAGS) $(SFMLINCLUDE)

%.o: %.cpp
	g++ $(INCLUDE)  -c $< -o $@ $(FLAGS) $(SFMLINCLUDE)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

exe:
	@make re
	@./$(NAME)
	@make fclean

v:
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME)

.PHONY:  all clean fclean re exe