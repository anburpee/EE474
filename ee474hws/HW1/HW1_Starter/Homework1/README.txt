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
(Paste here)

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
(Paste here)

---

Part III: Structs and Simulated Sensor Records

1. What is a pointer to a struct, and how is it used?  
Answer:


2. How does dynamic memory allocation work in C?  
Answer:

3. Why is dynamic allocation useful in embedded systems?  
Answer:

4. Copy your Serial Monitor output from Part III below:  
(Paste here)

---

Anything else you'd like us to know? (bugs, challenges, feedback, etc.):  
(Optional)
