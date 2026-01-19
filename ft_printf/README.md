*This project has been created as part of the 42 curriculum by alfeofan.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the standard `printf()` function from the C standard library.  
Its goal is to provide formatted output conversion without relying on the standard `printf` behavior.  
This project allows students to explore variadic functions, data formatting, and low-level output management in C.

`ft_printf` supports the following conversion specifiers:

- `%c` → print a single character
- `%s` → print a string
- `%p` → print a pointer address
- `%d` / `%i` → print a signed integer
- `%u` → print an unsigned integer
- `%x` / `%X` → print a number in hexadecimal format
- `%%` → print a literal percent sign

The function returns the number of characters printed, similar to the standard `printf()`.  

---

## Features

✔ Fully compatible with mandatory ft_printf requirements  
✔ Counts printed characters correctly  
✔ Handles NULL string and pointer cases  
✔ Uses variadic arguments via `<stdarg.h>`  
✔ Does not rely on `printf()` internally  
✔ Works on Linux and macOS  
✔ Zero memory leaks  

---

## Instructions

### **Compilation**

To compile the library:

```sh
make
