#include <stdio.h>
#include <string.h>

int main(){
    // function from stdio lib
    printf("Hello, World!\n");

    //array
    char* myIDs[32];
    myIDs[0] = "first element of array";
    printf("%s\n", myIDs[0]); //%i - int %c - character %s - string

    //array of string
    char new_str[] = {'h','i', 0};
    printf("%s\n", new_str);

    //array of hex
    char *str = "hehe";
    char otherstr[] = {0x68,0x65,0x68,0x65, 0} ;
    if (!strcmp(str, otherstr)) { // Проверка равенства строк с использованием strcmp. Возвращает true, если строки равны.
        printf("Yay!\n");
    } else {
        printf("Nay!\n");
    }

    // if, else if, else
    int number;
    scanf("%d", &number);

    if (number == 10) {
        printf("user has entered 10");
    } else if (number > 10) {
        printf("number is bigger than 10");
    } else {
        printf("number is lesser than 10");
    }


    return 0;
    // https://manual.cs50.io/3/printf
}