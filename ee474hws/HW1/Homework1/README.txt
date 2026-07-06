README.txt - HW1: Pointers and Embedded Thinking

Name:  
Date:  

---

General Instructions:

- This file is required as part of your submission.
- Fill in the answers to the questions for each part.
- Use this document to also describe your code and paste output.
- Be clear and concise.

---

Part I: C Basics – Variables and Pointers

1. What is the difference between a pointer and a variable?  
Answer: 
A variable is data that is stored in memory. Variables are types.
A pointer is an 8-byte address that points to a variable of a specified type(pointers are typed).

2. What happens when two pointers point to the same variable?  
Answer:
Then then the two pointers refer to the same address in memory. When multiple pointers
point to the same location in memory, then as the pointers are simultaneously dereferenced, there are
risks of hazards occuring if at least one access is trying to modify the data.

3. What is the benefit of accessing values through pointers?  
Answer:
Using pointers reduces the memory overhead because it eliminates the need to copy a value
whenever you are trying to modify or pass into functions.

4. Copy your Serial Monitor output from Part I below:  
=================== PART I ======================
a = 100, *p = 100
Address of a: 0x3fcebd0c
a = 55, *p = 55, *q = 55
Original b = 200
a = 55, New b = 200

---

Part II: Memory and Arrays

1. How are elements in an array laid out in memory? How do they differ between types (e.g., char vs int)?  
Answer:
Elements in an array live contiguously in memory. The difference between arrays of different types is
the amount of data each element takes up.

2. How does your my_memcpy() function work under the hood?  
Answer:
Given a source array and a destination buffer, each element in the source array is copied to the
destination buffer, one by one.

3. What situations in embedded systems might require memory-level copying?  
Answer:
An example of a situation you would want to transfer raw bytes is during the startup of a system
where you copy initial data from some non-volatile flash memory into SRAM for immediate access.

4. Copy your Serial Monitor output from Part II below:  
=================== PART II =====================
Integer array:
intArr[0] = 10, address: 0x3fcebcd8
intArr[1] = 20, address: 0x3fcebcdc
intArr[2] = 30, address: 0x3fcebce0
intArr[3] = 40, address: 0x3fcebce4
intArr[4] = 50, address: 0x3fcebce8
Char array:
charArr[0] = A, address: 0x3fcebcd3
charArr[1] = B, address: 0x3fcebcd4
charArr[2] = C, address: 0x3fcebcd5
charArr[3] = D, address: 0x3fcebcd6
charArr[4] = E, address: 0x3fcebcd7
dest: hello world

---

Part III: Structs and Simulated Sensor Records

1. What is a pointer to a struct, and how is it used?  
Answer:
A struct is stored in a contiguous block of memory. A pointer to a struct points to the start address
in memory where the struct is stored. A pointer to a struct is used when accessing the struct for
reads/writes, or during memory allocation for the struct (malloc) or freeing of it.


2. How does dynamic memory allocation work in C?  
Answer:
Dynamic memory allocation allocates memory in the heap during runtime, as opposed to static
memory that is allocated in the stack during compile time. Whenever you allocate memory using
malloc, you must be sure to call free() to free up the memory after use.

3. Why is dynamic allocation useful in embedded systems?  
Answer:
Dynamic memory allocation is used in embedded systems because when you are are working with a
limited amount of memory (Which you pretty much always are), it's better to allocate only as much
memory as strictly necessary through malloc during runtime instead of allocating a huge amount of
unnecessary memory (that is predicted to be needed) during compile time that will only partially
be used.

4. Copy your Serial Monitor output from Part III below:  
=================== PART III ====================
Sensor 0 - ID: 123, Label: label0, Reading: 1.230000
Updated sensor 0 reading via pointer: 1.230000
Sensor 1 - ID: 123, Label: label0, Reading: 2.340000

Allocated 3 sensors...
Sensor 0 - ID: 100, Label: T0, Reading: 0.670000
Sensor 1 - ID: 101, Label: T1, Reading: 1.670000
Sensor 2 - ID: 102, Label: T2, Reading: 2.670000

---

Anything else you'd like us to know? (bugs, challenges, feedback, etc.):  

I did all of HW1 on VS Code using Aruduino CLI and it worked pretty well.
