# Libftprintf - 42 Core Project

This project is a custom implementation of the `printf` function in C, developed as part of the 42 school curriculum. It replicates the behavior of the standard `printf` while handling various format specifiers and ensuring robustness.

## Features
- Supports format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Handles variable-length arguments using `va_list`
- Efficient memory management and error handling
- Compatible with standard C libraries

## Installation
Clone the repository and compile the library:

```bash
git clone XX
cd libftprintf
make
```
Usage
To use libftprintf in your project, include the header file and link the compiled library:

```bash
#include "libftprintf.h"

int main()
{
    ft_printf("Hello, %s!\n", "world");
    return 0;
}
```
Compile with:

```bash
gcc main.c libftprintf.a -o test_program
