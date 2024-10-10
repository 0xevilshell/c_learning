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

    // simple pointer to variable
    int q = 1;
    int *pQ = &q;
    printf("%d\n", *pQ);

    // pointer to array
    int arr[3] = {1, 5, 7};
    int *pArr = arr; //not need & in array pointer
    printf("%d\n", *(arr + 0)); // 1 'cause 1 is 0 element of array, also need () after *

    int g = 101;
    int *pG = &g;
    int **pGG = &pG; // pointer to pointer
    printf("%d\n", **pGG); // **



    return 0;
}
