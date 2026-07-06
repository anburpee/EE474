#include <stdint.h> // need to include for uint8_t
#include <stdio.h>
#include <string.h>
#include "hwlib.h"


void my_memcpy(void* dest, const void* src, size_t size) {
    // =================> TODO: Implement byte-by-byte memory copy using uint8_t*
    uint8_t* dest1 = (uint8_t*)dest;
    const uint8_t* src1 = (uint8_t*)src;
    for (size_t i = 0; i < size; i ++) {
        dest1[i] = src1[i];
    }
}

void run_pointer_basics() {

    // Step 1
    // =================> TODO: Declare and initialize an int[5] array
    int intArr[5] = {10, 20, 30, 40, 50};

    // =================> TODO: Declare and initialize a char[5] array
    char charArr[5] = "ABCDE";

    // =================> TODO: Print value and address of each element using a for loop
    printf("Integer array:\n");
    for (int i = 0; i < 5; i++) {
        printf("intArr[%d] = %d, address: %p\n", i, intArr[i], (void*)(&intArr[i]));
    }
    printf("Char array:\n");
    for (int i = 0; i < 5; i++) {
        printf("charArr[%d] = %c, address: %p\n", i, charArr[i], (void*)(&charArr[i]));
    }


    // Step 2
    // =================> TODO: Declare source string and destination buffer
    char str[] = "hello world";
    char dest[20] = {};

    // =================> TODO: Use my_memcpy() to copy string
    my_memcpy(dest, str, strlen(str) + 1); // strlen() doesn't include null terminator

    
    // =================> TODO: Print copied string
    printf("dest: %s\n", dest);
}
