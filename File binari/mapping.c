#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

int main()
{
    int file = open("esempio.dat", O_RDONLY | O_CREAT);
    char buff[5];
    assert(file >= 0);
    read(file, buff, sizeof(buff));
    puts(buff);
    close(file);

    return 0;
}