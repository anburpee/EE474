#include <stdio.h>
#include <string.h>
#include "hwlib.h"


void my_memcpy(void* dest, const void* src, size_t size) {
    // =================> TODO: Implement byte-by-byte memory copy using uint8_t*
    uint8_t* dest1 = (uint8_t*)dest;
    const uint8_t* src1 = (uint8_t*)src;
    for (int i = 0; i < size; i ++) {
        dest1[i] = src1[i];
    }
}

void run_pointer_basics() {

    // Step 1
    // =================> TODO: Declare and initialize an int[5] array
    int intArr[5] = {0, 1, 2, 3, 4};

    // =================> TODO: Declare and initialize a char[5] array
    char charArr[5] = "yooo";

    // =================> TODO: Print value and address of each element using a for loop
    for (int i = 0; i < 5; i++) {
        printf("Address of intArr[%d]: %p\n", i, (void*)(&intArr[i]));
    }
    for (int i = 0; i < 5; i++) {
        printf("Address of charArr[%d]: %p\n", i, (void*)(&charArr[i]));
    }


    // Step 2
    // =================> TODO: Declare source string and destination buffer
    char str[] = "hello world";
    char dest[20] = {};

    // =================> TODO: Use my_memcpy() to copy string
    my_memcpy(dest, str, 20);

    
    // =================> TODO: Print copied string
    printf("dest: %s", dest);
}
