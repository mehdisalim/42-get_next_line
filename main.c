#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("text3.txt", O_RDONLY);
    printf("|%s|",get_next_line(fd));
    printf("|%s|",get_next_line(fd));
    // char text[10];
    // int i = read(10000, text, 12254);
    // printf("%s\n%i\n",text, i);
    return 0;
}
