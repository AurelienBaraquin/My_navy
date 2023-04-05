##
## EPITECH PROJECT, 2023
## my_lib
## File description:
## Makefile
##

SRC = *.c
OBJ = $(SRC:.c=.o)
TARGET = libmy.a
INC = -I./
LIB = -L./ -lmy
CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CMP = gcc

$(TARGET) : $(OBJ)
	ar rc $(TARGET) $(OBJ)

all :	$(TARGET)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all
