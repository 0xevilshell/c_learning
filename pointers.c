#include <stdio.h>

int x = 0;
int *pointerofX = &x;

typedef struct Ulthuan {
    char *nation;
    int age;
} Ulthuan;

void create_kingdoms(Ulthuan *e) {
    e->nation = "High Elves";
    e->age = 1000;

    return;
}

//Ulthuan Caledor ()

int main(int argc, char const *argv[])
{
    printf("%d\n", *pointerofX);
    printf("%p\n", pointerofX); //0xaaaadbf60044

    struct Ulthuan Caledor;
    create_kingdoms(&Caledor);
    printf("%s\n", Caledor.nation);

    // 



    return 0;
}
