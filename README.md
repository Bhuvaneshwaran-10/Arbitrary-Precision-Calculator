# Arbitrary Precision Calculator (APC)

## Overview

The **Arbitrary Precision Calculator (APC)** is a Data Structures and Algorithms project implemented in **C** using **Linked Lists**. The project is designed to perform arithmetic operations on very large numbers that cannot be handled using standard C data types.

Each digit of a number is stored in a node of a linked list, allowing the calculator to process numbers with virtually unlimited length.

---

## Features

* Addition of large numbers
* Subtraction of large numbers
* Multiplication of large numbers
* Division of large numbers
* Modular and structured implementation
* Linked List based storage for arbitrary length integers
* Handles numbers beyond primitive datatype limits

---

## Technologies Used

* C Programming
* Data Structures
* Linked Lists
* Modular Programming
* Makefile
* GCC Compiler

---

## Project Structure

```bash
.
├── main.c
├── Addition.c
├── Subtraction.c
├── Multiplication.c
├── Division.c
├── Functions.c
├── Functions.h
├── Makefile
└── a.out
```

---

## Working Principle

The calculator stores each digit of a number in a separate linked list node. Arithmetic operations are performed digit by digit similar to manual mathematical calculations.

### Example

Input:

```text
99999999999999999999 + 1
```

Output:

```text
100000000000000000000
```

---

## Compilation and Execution

### Compile the Project

```bash
make
```

### Run the Executable

```bash
./Arbitrary_Precision_Calculator
```

---

## Sample Operations

### Addition

```text
Enter Number 1 : 123456789123456789
Enter Number 2 : 987654321987654321
Result : 1111111111111111110
```

### Multiplication

```text
Enter Number 1 : 999999999
Enter Number 2 : 999999999
Result : 999999998000000001
```

---

## Learning Outcomes

* Improved understanding of Linked Lists
* Learned implementation of arithmetic algorithms using data structures
* Enhanced debugging and problem-solving skills
* Gained knowledge in modular programming and memory management
* Understood handling of very large numerical computations in C

---

## Future Enhancements

* Support for negative numbers
* Floating point large number operations
* Expression evaluation support
* GUI-based calculator interface
* File input and output support

---

## Author

**Bhuvaneshwaran P**

---

## License

This project is developed for educational and learning purposes.
