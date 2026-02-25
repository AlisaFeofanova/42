*This project has been created as part of the 42 curriculum by <alfeofan>.*

# ft_printf

## Description

This project is part of the **42 curriculum**.  
The main objective is to recreate the standard C function `printf`.

The goal is to implement a function called `ft_printf` that behaves similarly to the original `printf`, handling formatted output and a variable number of arguments.

This project focuses on:
- understanding variadic functions (`stdarg.h`)
- low-level output using `write`
- string and number formatting
- recursion and memory-safe programming

Through this project, we deepen our understanding of C and system-level programming.

---

## Instruction

### Requirements

- C compiler (e.g. `cc`)
- Make 
- Unix-based system (Linux / macOS)

Allowed libraries:
- `unistd.h`
- `stdarg.h`
- `stdlib.h`

---

# ft_printf — Detailed Code Explanation

This function reproduces a simplified version of the standard printf.
It prints formatted output to the standard output (stdout)
and returns the total number of characters printed.

It uses variadic arguments through the <stdarg.h> macros:

| `va_list` | type used to store information about variable arguments |
| `va_start` | initializes the argument list |
| `va_arg` | retrieves the next argument of a given type |
| `va_end` | cleans up the argument list |

---

# ft_check_flag

This static helper function handles format specifiers.
It receives:
  - c: the format character following '%'
  - args: the current variadic arguments list

Depending on the specifier, it retrieves the correct argument
from the va_list and prints it using the corresponding function.

It returns the number of characters printed.

```c
static int	ft_check_flag(char c, va_list args)
{
	if (c == 'c')
		/* Print a single character */
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		/* Print a string */
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		/* Print a signed integer */
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		/* Print an unsigned integer */
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		/* Print a hexadecimal number (lowercase) */
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		/* Print a hexadecimal number (uppercase) */
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		/* Print a pointer address */
		return (ft_putptr(va_arg(args, void *)));
	else if (c == '%')
		/* Print a literal '%' character */
		return (ft_putchar('%'));
	return (0);
}
```

# ft_printf

Main function that parses the format string and prints output.

Parameters:
 - format: a string containing text and format specifiers
 - ...   : a variable number of arguments

The function iterates through the format string character by character.
When '%' is found, the next character is treated as a format specifier.

The function returns the total number of printed characters.

```c
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	/* Initialize the variadic argument list */
	va_start(args, format);

	count = 0;
	i = 0;

	/* Safety check for NULL format string */
	if (!format)
		return (-1);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			/* Handle format specifier */
			count += ft_check_flag(format[i + 1], args);
			i++;
		}
		else
		{
			/* Print a regular character */
			count += ft_putchar(format[i]);
		}
		i++;
	}

	/* Clean up the variadic argument list */
	va_end(args);

	return (count);
}
```
--- 

# ft_printf.h — Header File Documentation

## Overview

The `ft_printf.h` header file contains all necessary function prototypes,
library inclusions, and include guards required for the implementation
of the `ft_printf` project.

It serves as the central interface between the `ft_printf` core logic
and its helper functions, ensuring consistency and proper compilation
across all source files.

## Include Guards

```c
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
```
Include guards prevent multiple inclusions of the same header file
during compilation, which could otherwise lead to redefinition errors.

```c
#endif
```
Closes the include guard.

## Included Libraries

```c
# include <stdarg.h>
```

Used for handling functions with a variable number of arguments.
Provides access to:
- `va_list`
- `va_start`
- `va_arg`
- `va_end`
These macros are essential for implementing the `ft_printf` function.

```c
# include <unistd.h>
```

Provides access to low-level I/O functions such as `write`,
which is used to output characters to the standard output (`stdout`).

```c
# include <stdlib.h>
```

Provides standard utility functions and types.
It is mainly used for memory-related operations within helper functions.

## Function Prototypes

```c
int ft_printf(const char *format, ...);
```

Description:
Main formatted output function. It parses the format string, processes
format specifiers, prints the corresponding output to `stdout`,
and returns the total number of printed characters.

---

```c
int ft_putchar(int c);
```

Description:
Writes a single character to the standard output.
Return value:
Number of characters written (always 1).

```c
/*
** ft_putchar:
** Writes a single character to the standard output (stdout).
**
** Parameters:
**   c - the character to print (passed as int)
**
** How it works:
**   - write(1, &c, 1) sends 1 byte to file descriptor 1 (stdout)
**   - &c is the address of the character
**
** Return:
**   Always returns 1 (since exactly one character is printed)
*/
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
```

---

```c
int ft_putstr(char *s);
````

Description:
Writes a null-terminated string to the standard output.
Special behavior:
If the string pointer is `NULL`, the function typically prints `(null)`.
Return value:
Number of characters written.

```c
/*
** ft_putstr:
** Prints a string to stdout.
**
** Parameters:
**   s - pointer to the string
**
** How it works:
**   - If s is NULL, prints "(null)"
**   - Otherwise, calculates string length using ft_strlen
**   - Writes the string using write
**
** Return:
**   Number of characters printed
*/
int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
```

---

```c
int ft_putnbr(int n);
````

Description:
Writes a signed integer to the standard output.
Return value:
Number of characters written.

```c
/*
** ft_putnbr:
** Prints a signed integer.
**
** Parameters:
**   n - integer to print
**
** How it works:
**   - Uses long to safely handle INT_MIN
**   - If negative, prints '-' and converts to positive
**   - Uses recursion to print digits from left to right
**
** Example:
**   123 -> '1' '2' '3'
**
** Return:
**   Number of characters printed
*/
int	ft_putnbr(int n)
{
	long	nbr;
	char	c;
	int		count;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
```

---

```c
int ft_putunbr(unsigned int n);
````

Description:
Writes an unsigned integer to the standard output.
Return value:
Number of characters written.

```c
/*
** ft_putunbr:
** Prints an unsigned integer.
**
** Parameters:
**   n - unsigned int
**
** How it works:
**   - Recursively divides number by 10
**   - Prints digits from most significant to least
**
** Return:
**   Number of characters printed
*/
int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
```

---

```c
int ft_puthex(unsigned int n, int upper);
````

Description:
Writes an unsigned integer in hexadecimal format.
Parameters:
- `n` — the number to convert
- `upper` — determines letter case:
    - `0` → lowercase (`abcdef`)
    - `1` → uppercase (`ABCDEF`)
Return value:
Number of characters written.

```c
/*
** ft_puthex:
** Prints an unsigned integer in hexadecimal format.
**
** Parameters:
**   n      - number to print
**   format - 0 for lowercase, 1 for uppercase
**
** How it works:
**   - Selects base depending on format
**   - Recursively divides by 16
**   - Prints digits using base string
**
** Example:
**   255 -> ff or FF
**
** Return:
**   Number of characters printed
*/
int	ft_puthex(unsigned int n, int format)
{
	int			count;
	const char	*base;

	count = 0;
	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	count += ft_putchar(base[n % 16]);
	return (count);
}
```

---

```c
int ft_putptr(void *ptr);
````

Description:
Writes a memory address (pointer) in hexadecimal format,
prefixed with `0x`.
Return value:
Number of characters written.

```c
/*
** Helper function:
** Prints a number in hexadecimal (for pointer)
*/
static int	hex(unsigned long n)
{
	int			count;
	const char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

/*
** ft_putptr:
** Prints a pointer address.
**
** Parameters:
**   ptr - pointer to print
**
** How it works:
**   - Converts pointer to unsigned long
**   - Prints "0x" prefix
**   - Prints address in hex
**   - If NULL -> prints "(nil)"
**
** Return:
**   Number of characters printed
*/
int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				len;

	address = (unsigned long)ptr;
	len = 0;
	if (!address)
		return (write(1, "(nil)", 5), 5);
	len += write(1, "0x", 2);
	return (len + hex(address));
}
```

---

```c
int ft_strlen(const char *s);
```

Description:
Calculates the length of a null-terminated string.
Return value:
Number of characters before the null terminator.

```c
/*
** ft_strlen:
** Calculates the length of a string.
**
** Parameters:
**   s - string
**
** How it works:
**   - Iterates until '\0'
**
** Return:
**   Length of string
*/
int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
```

---

## Design Considerations

- All helper functions return the number of characters printed,
allowing `ft_printf` to accurately track the total output length.
- The header file enforces clear separation between interface and implementation.
- Only standard C libraries allowed by the 42 curriculum are used.

---

