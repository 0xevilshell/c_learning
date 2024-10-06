#include <stdio.h>
#include <stdbool.h>

#define MAX_EMPLOYEES 10

typedef struct employee_type // use typedef to not use word struct before variable type
{
    int id;
    char name;
    float salary;
    bool isSenior;
} employee_type; // employee_type also part of typedef


int main() {

    employee_type employees[MAX_EMPLOYEES];
    
    int i = 0;
    for (i = 0; i < MAX_EMPLOYEES; i++)
    {
        employees[i].id = i; // + 1 if we want first id to be 1
        printf("Employee ID: %d\n", employees[i].id);
    }
    

    return 0;
}
