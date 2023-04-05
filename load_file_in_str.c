/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/
#include "navy.h"

char *load_file_in_str(char const * filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat a;
    stat(filepath, &a);
    int size = a.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}
