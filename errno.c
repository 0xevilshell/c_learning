#include <stdio.h>
#include <fcntl.h>  // Для open()
#include <errno.h>  // Для errno
#include <string.h> // Для strerror()

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s needs a <filename> monka!\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT);
    
    if (fd == -1) {  // Если ошибка
        perror("open");  // Используем perror для печати сообщения об ошибке
        return -1;
    }

    

    return 0;
}