#include <stdio.h>
#include <stdlib.h>



int main() {
    int* p = (int*)malloc(sizeof(int));
    *p = 42; 
    printf("%d\n", *p); //42
    printf("%d\n", p); //-361135456 , why?
    printf("%p\n", (void*)p); //0xaaaaea7982a0
    
    free(p); 

    return 0;
}
