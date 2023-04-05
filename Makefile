##
## EPITECH PROJECT, 2023
## B-PSU-100-MPL-1-1-navy-aurelien.baraquin
## File description:
## Makefile
##

CC = gcc
SRC = 	*.c

TARGET = navy

$(TARGET) :
	$(CC) -o $(TARGET) $(SRC) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3

all :	$(TARGET)

clean :
	rm -rf

fclean : clean
	rm -rf $(TARGET)

re : fclean all