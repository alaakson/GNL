#include <stdio.h>
#include <fcntl.h> // For open()
#include <unistd.h> // For close()
#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Free the line allocated by get_next_line
    }

    if (close(fd) < 0)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
}
