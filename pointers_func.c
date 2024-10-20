#include <stdio.h>
#include <stdlib.h>

// Функция foo выделяет память для указателя и присваивает значение 10
int foo(int **ptr) {
    *ptr = (int *)malloc(sizeof(int));  // Выделяем память для одного элемента типа int

    if (*ptr == NULL) {  // Проверяем, удалось ли выделить память
        fprintf(stderr, "Memory allocation failed\n");
        return -1;  // Возвращаем -1, если выделение памяти не удалось
    }
    **ptr = 10;  // Присваиваем значение 10 области памяти, на которую указывает *ptr
    return 0;  // Возвращаем 0, если все прошло успешно
}

int main() {
    int *ptr = NULL;  // Инициализируем указатель ptr значением NULL

    // Первый вызов foo: выделяем память и присваиваем значение 10
    if (foo(&ptr) != 0) {  /*Если foo возвращает ненулевое значение, значит произошла ошибка. 0 HERE IS A FUCKING
    RETURN CODE FROM ФУКЦНИИ FOO АХАХ КАКОГО XYZ!!!!
    THIS IS MOST IMPORTANT LINE OF CODE TO UNDERSTAND POINTERS*/ 
        return 0;  // Завершаем программу, если выделение памяти не удалось
    }

    // Выводим значение, на которое указывает ptr
    printf("Value: %d\n", *ptr);  // Разыменовываем указатель ptr, чтобы получить значение (ожидается 10)

    // Освобождаем выделенную память
    free(ptr);  // Освобождаем память, чтобы избежать утечки. command below to check leak memory
    // gcc -o pointers_f ./pointers_func.c -g 
    // valgrind --leak-check=full ./pointers_f -s

    // ONE MORE TIME
    char a, b, c, *p;

    a = 'A';
    p = &a; //p when address
    b = *p;
    p = &c;
    *p = 'Z'; // *p when value

    printf("%c %c %c\n", a, b, c); // A A Z

    int num = 10; // initial value 
    void minus10(int *v) { // int * v here is storing address of variable. we take num (adress) and store it into v. we take num because its type of INT - this is very important!
    
        *v = *v - 10; //this means I am v, I point to num address via & sign, thats why I get acces into num's value, which equals 10;
    /* De_referenc_ing is a technique for accessing or manipulating data stored in a memory location pointed to by a pointer.
     
        Передача Адреса (&):
	•	Вы передаёте адрес переменной num в функцию. Это позволяет функции работать с оригинальной переменной, а не с её копией.
	
    	Указатель (v):
	•	Параметр v является указателем, который хранит адрес переменной num.
	•	Это означает, что любые изменения, сделанные через разыменование *v, будут напрямую влиять на значение переменной num.
	
    	Разыменование (*v):
	•	*v даёт вам доступ к значению, на которое указывает v. Это означает, что через *v вы можете как читать, так и изменять значение этой переменной. */
    }
    
    minus10(&num); //send as address
    printf("%d\n", num); // changed initial value after function

    return 0;  // Завершаем программу
}