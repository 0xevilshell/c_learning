#include <stdio.h>
#include <fcntl.h>  // Для open()
#include <errno.h>  // Для errno
#include <string.h> // Для strerror()

int main(int argc, char *argv[]) {
    int fd = open("./file-that-doesnt-exist", O_RDONLY);
    if (fd == -1) {  // Если ошибка
        perror("open");  // Используем perror для печати сообщения об ошибке
        return -1;
    }
    return 0;
}