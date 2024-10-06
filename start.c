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
    int number = 5;
    //scanf("%d", &number);

    if (number == 10) {
        printf("user has entered 10");
    } else if (number > 10) {
        printf("number is bigger than 10\n");
    } else {
        printf("number is lesser than 10\n");
    }

    //loops
    int loopIDs[10];
    //for 
    int i = 0;
    for (int i = 0; i < sizeof(loopIDs)/sizeof(loopIDs[0]); i++)
    {
        printf("%d\n", i);
    }
    
    //while
    int a = 0;
    while (a <= sizeof(loopIDs)/sizeof(loopIDs[0])) {
        printf("this is while %d\n", a);
        a++;
    }

    // do - while
    int b = 0;
    do {
        printf("this is DO while %d\n", b);
        b++;
    } while (b < sizeof(loopIDs)/sizeof(loopIDs[0]));

    //functions
    // return_type name(list of arguments) {
    //   code
    // }
    int add(int o, int p){
        int t = o + p;

        return t; //Когда функция выполняется, в какой-то момент нужно вернуться к месту, где она была вызвана, чтобы продолжить выполнение основной программы. Это называется возвратом. 
    }

    int another_int = add(5, 55);
    printf("%d\n", another_int);

    return 0;
    // https://manual.cs50.io/3/printf
}