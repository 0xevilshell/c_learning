#include <stdio.h>
#include <fcntl.h>  // Для open()
#include <errno.h>  // Для errno
#include <string.h> // Для strerror()
#include <unistd.h>


int main(int argc, char *argv[]) { //c - count of program arguments. first (1) is a program itself
// v - number of arguments from 0 to n.. 0 - program itself, 1 - first agrument. example ./myprog -f, -f is a first agrument

    if (argc != 2) {
        printf("Usage: %s needs a <filename> monka!\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 0644); /*
    Права доступа задаются следующим образом:

        4 — r (read) — право чтения.
        2 — w (write) — право записи.
        1 — x (execute) — право выполнения.

        Цифры могут складываться, чтобы выразить комбинацию прав:
        6 (4 + 2) — чтение (r) и запись (w).
        4 — только чтение (r).
        7 (4 + 2 + 1) — чтение (r), запись (w), выполнение (x).

        0 means numbers are in 8 decimal from 0 to 7
        6 — Права для владельца файла.
        4 — Права для группы.
        4 — Права для всех остальных.


    */
    
    if (fd == -1) {  // Если ошибка
        perror("open");  // Используем perror для печати сообщения об ошибке
        return -1;
    }

    char *data_s = "what is this \n";
    write(fd, data_s, strlen(data_s));
    close(fd);

    
    return 0;
}