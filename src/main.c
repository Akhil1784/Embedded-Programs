#include <stdlib.h>
#include <stdio.h>

void create_leak() {
    int *ptr = malloc(10 * sizeof(int)); 
    ptr[0] = 100;
    printf("Pointer inside function: %p\n", (void*)ptr);
}

int main() {
    create_leak();
    printf("Leak created.\n");
    return 0;
}