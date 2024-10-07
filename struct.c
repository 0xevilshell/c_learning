#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 10

typedef struct __attribute__((__packed__)) employee_type // use typedef to not use word struct before variable type
{
    int id;
    char name;
    float salary;
    bool isSenior;

    union { // making union - sharing same memory
        int x;
        char y;
    };
} employee_type; // employee_type also part of typedef - nickname for the struct


int main() {
    // employee_type is type of empoyees variable, then [] are array
    employee_type employees[MAX_EMPLOYEES];
    
    int i = 0;
    for (i = 0; i < MAX_EMPLOYEES; i++)
    {
        employees[i].id = i; // + 1 if we want first id to be 1
        printf("Employee ID: %d\n", employees[i].id);
    }
    
    employees[0].x = 0x41424344;
    printf("%c\n", employees[0].y);

    printf("%d\n", sizeof(struct employee_type));

    return 0;
}
