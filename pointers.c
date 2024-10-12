#include <stdio.h>
#include <stdlib.h>

#define MAX_KINGDOMS 10

int x = 0;
int *pointerofX = &x;

typedef struct Ulthuan {
    char *nation;
    int age;
    int id;
} Ulthuan;

int create_kingdoms(Ulthuan *e) {
    static int numKingdoms = 0;
    numKingdoms++;

    e->id = numKingdoms;
    e->nation = "High Elves";
    e->age = 1000;

    return numKingdoms;
}

//Ulthuan Caledor ()

int main(int argc, char const *argv[])
{
    printf("%d\n", *pointerofX);
    printf("%p\n", pointerofX); //0xaaaadbf60044

    struct Ulthuan Caledor;
    create_kingdoms(&Caledor);
    printf("%s\n", Caledor.nation);

    struct Ulthuan *united_kingdoms = malloc(sizeof(struct Ulthuan) * MAX_KINGDOMS);
    if (united_kingdoms == NULL) {
        printf("allocator failed\n");
        return -1;
    }

    create_kingdoms(&united_kingdoms[0]); // creating kingdom number 0 in array
    united_kingdoms[0].nation = "Avelorn"; // assign from default HE to Avelorn
    printf("%s\n", united_kingdoms[0].nation);
    printf("Kingdoms size is %d\n", sizeof(united_kingdoms[0]));

    //int i = 1;
    for (int i = 0; i < MAX_KINGDOMS; i++) {
        int id = create_kingdoms(&united_kingdoms[i]);
        printf("Kingdom id is %d\n", id);
    }

    // Освобождение памяти для всего массива
    free(united_kingdoms);
    united_kingdoms = NULL;
    printf("Kingdoms size is %d\n", sizeof(united_kingdoms));
    printf("%s\n", united_kingdoms[0].nation); // segmentation fault

    // simple pointer to variable
    int q = 1;
    int *pQ = &q;
    printf("%d\n", *pQ);

    // pointer to array
    int arr[3] = {1, 5, 7};
    int *pArr = arr; //not need & in array pointer
    printf("%d\n", *(arr + 0)); // 1 'cause 1 is 0 element of array, also need () after *

    // pointer to pointer
    int g = 101;
    int *pG = &g;
    int **pGG = &pG; // pointer to pointer
    printf("%d\n", **pGG); // **

    // pointer to function
    int lord_attack(int sorcery, int damage) {
        return sorcery * damage;
    }
    /* pointer to attack funtion */ 
    int (*attack_ptr)(int, int) = &lord_attack; // pointer must have type!!!
    printf("Lords attack is %d\n", attack_ptr(52, 25));

    // pointer to array of pointers
    int a = 5, b = 10, c = 15;
    int *array_ptr[3] = {&a, &b, &c}; // array has [3] elements
    printf("array has %d element \n", *array_ptr[0]); // array must have *

    return 0;
}
