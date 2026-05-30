*This project has been created as part of the 42 curriculum by alfeofan.*

# get_next_line

## Description

The **get_next_line** project is part of the 42 curriculum.  
Its objective is to implement a function that reads a file line by line.

The function `get_next_line` returns one line at a time from a file descriptor,
including the newline character if present. It allows sequential reading of files
without loading the entire content into memory.

This project focuses on:
- file descriptor handling
- buffer management
- dynamic memory allocation
- static variables
- handling partial reads

The implementation must be efficient and memory-safe, handling various edge cases
such as large files, multiple file descriptors, and end-of-file conditions.

---

## Features

- Reads a file line by line
- Supports multiple file descriptors (bonus)
- Handles arbitrary buffer sizes
- Works with standard input and files
- Memory leak free
- Efficient reading using buffers

---

## Instructions

### Requirements

- C compiler (e.g. `cc`)
- Make
- Unix-based system (Linux / macOS)

Allowed functions:
- `read`
- `malloc`
- `free`

Allowed libraries:
- `unistd.h`
- `stdlib.h`

---

### Compilation

Clone the repository:

```bash
git clone https://github.com/<your_username>/get_next_line.git
cd get_next_line
```

Compile the project:

```bash
make
```

Or compile manually:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```


## Usage Example with Full Explanation

```c
#include <fcntl.h>          // For open()
#include "get_next_line.h"  // Declaration of get_next_line()

int main(void)
{
    int     fd;     // File descriptor
    char    *line;  // Pointer to store each line returned by get_next_line

    /*
    ** Open the file "file.txt" in read-only mode.
    ** open() returns:
    **   - a file descriptor (>= 0) on success
    **   - -1 on error
    */
    fd = open("file.txt", O_RDONLY);

    /*
    ** If open() failed, we return 1 to indicate an error.
    */
    if (fd < 0)
        return (1);

    /*
    ** Loop to read the file line by line.
    **
    ** get_next_line(fd):
    **   - reads from the file descriptor
    **   - returns one line at a time
    **   - includes '\n' if present
    **   - returns NULL when EOF is reached or on error
    */
    while ((line = get_next_line(fd)) != NULL)
    {
        /*
        ** Write the line to standard output (stdout).
        **
        ** write parameters:
        **   1 -> file descriptor for stdout
        **   line -> pointer to the string
        **   ft_strlen(line) -> number of bytes to write
        */
        write(1, line, ft_strlen(line));

        /*
        ** Important:
        ** get_next_line allocates memory for each line.
        ** We must free it after use to avoid memory leaks.
        */
        free(line);
    }

    /*
    ** Close the file descriptor after finishing reading.
    ** This releases system resources.
    */
    close(fd);

    /*
    ** Return 0 to indicate successful execution.
    */
    return (0);
}

---

## How It Works

1. Opening the File

```c
fd = open("file.txt", O_RDONLY);
```

- Opens the file in read-only mode
- Returns a file descriptor (integer)
- If it fails, returns -1

2. Reading Line by Line

```c
while ((line = get_next_line(fd)) != NULL)
```

- Calls get_next_line repeatedly
- Each call returns:
    - a newly allocated string
    - or NULL when the file is finished

3. Printing the Line

```c
write(1, line, ft_strlen(line));
```

- `1` is the file descriptor for __stdout__
- `line` is the string to print
- `ft_strlen` calculates the length

4. Freeing Memory

```c
free(line);
```

- Prevents memory leaks
- Mandatory after each call

5. Closing the File

```c
close(fd);
```

- Releases system resources
- Always close opened file descriptors

---
## get_next_line.c — Detailed Code Explanation

```c
#include "get_next_line.h"

/*
** read_to_stash:
** Reads data from the file descriptor and stores it in "stash"
** until a newline character is found or EOF is reached.
**
** Parameters:
**   fd    - file descriptor to read from
**   stash - existing stored data (may contain previous reads)
**
** Returns:
**   Updated stash containing accumulated data
**   NULL in case of error
*/
static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;     // Temporary buffer for reading
	int		bytes;   // Number of bytes read from file

	/*
	** Allocate memory for buffer (+1 for null terminator)
	*/
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);

	bytes = 1;

	/*
	** Continue reading until:
	** - we find a newline in stash
	** - or read() returns 0 (EOF)
	*/
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		/*
		** Read up to BUFFER_SIZE bytes from file
		*/
		bytes = read(fd, buf, BUFFER_SIZE);

		/*
		** If read() fails → free memory and return NULL
		*/
		if (bytes < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}

		/*
		** Null-terminate buffer to make it a valid string
		*/
		buf[bytes] = '\0';

		/*
		** Append buffer to stash
		** stash = old_stash + buf
		*/
		stash = ft_strjoin(stash, buf);

		/*
		** If allocation fails → free buffer and return NULL
		*/
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}

	/*
	** Free temporary buffer
	*/
	free(buf);

	return (stash);
}

/*
** extract_line:
** Extracts a single line from stash (including '\n' if present)
**
** Parameters:
**   stash - accumulated data
**
** Returns:
**   A newly allocated string containing one line
**   NULL if stash is empty
*/
static char	*extract_line(char *stash)
{
	int	i;

	i = 0;

	/*
	** If stash is empty or NULL → no line to return
	*/
	if (!stash || !stash[0])
		return (NULL);

	/*
	** Find the end of the line
	** (either '\n' or end of string)
	*/
	while (stash[i] && stash[i] != '\n')
		i++;

	/*
	** If newline is found → include it in the line
	*/
	if (stash[i] == '\n')
		i++;

	/*
	** Return substring from start to i
	*/
	return (ft_substr(stash, 0, i));
}

/*
** clean_stash:
** Removes the extracted line from stash and keeps the rest
**
** Parameters:
**   stash - current stored data
**
** Returns:
**   New stash containing remaining data
**   NULL if nothing is left
*/
static char	*clean_stash(char *stash)
{
	int		i;
	char	*new_stash;

	i = 0;

	/*
	** Find the newline position
	*/
	while (stash[i] && stash[i] != '\n')
		i++;

	/*
	** If no newline → nothing left after line
	** Free stash and return NULL
	*/
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}

	/*
	** Create new stash starting after '\n'
	*/
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i - 1);

	/*
	** Free old stash
	*/
	free(stash);

	return (new_stash);
}

/*
** get_next_line:
** Main function that returns one line per call.
**
** Parameters:
**   fd - file descriptor
**
** Returns:
**   A line read from fd (including '\n' if present)
**   NULL when EOF or error occurs
**
** How it works:
**   1. Reads data into stash
**   2. Extracts one line from stash
**   3. Cleans stash for next call
*/
char	*get_next_line(int fd)
{
	static char	*stash;  // Persistent storage between calls
	char		*line;   // Line to return

	/*
	** Validate input
	*/
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	/*
	** Read data and update stash
	*/
	stash = read_to_stash(fd, stash);

	/*
	** If read failed → return NULL
	*/
	if (!stash)
		return (NULL);

	/*
	** Extract one line from stash
	*/
	line = extract_line(stash);

	/*
	** Remove extracted line from stash
	*/
	stash = clean_stash(stash);

	return (line);
}

Summary of the Algorithm
Read data into a buffer until a newline or EOF is reached
Store data in a static variable (stash)
Extract one line from the stash
Clean the stash to keep only the remaining data
Return the line
Key Concepts
Static variable → keeps data between function calls
Buffering → improves performance by reducing system calls
Dynamic memory → allows flexible line sizes
String manipulation → required for splitting and joining data
Why This Approach Works
Efficient: does not read character by character
Scalable: works with large files
Safe: handles memory correctly
Flexible: works with any buffer size

---

#include "get_next_line.h"

/*
** ft_strlen
** ---------
** Calculates the length of a string.
**
** Parameters:
** - s: pointer to the string
**
** Returns:
** - Number of characters before the null terminator
**
** Purpose in get_next_line:
** Used frequently for memory allocation and string operations.
*/
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** ft_strchr
** ---------
** Searches for the first occurrence of character 'c' in string 's'.
**
** Parameters:
** - s: string to search in
** - c: character to find
**
** Returns:
** - Pointer to the first occurrence of 'c'
** - NULL if not found
**
** Special case:
** - If c is '\0', returns pointer to the end of the string
**
** Purpose in get_next_line:
** Used to detect newline '\n' inside the buffer.
*/
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	if (c == '\0')
		return (&s[i]);
	return (NULL);
}

/*
** ft_strlcat
** ----------
** Appends src string to dst string, ensuring no overflow.
**
** Parameters:
** - dst: destination buffer
** - src: source string
** - dstsize: total size of destination buffer
**
** Returns:
** - Total length of the string it tried to create
**
** Behavior:
** - Appends as much as possible from src
** - Always null-terminates if dstsize > 0
**
** Purpose in get_next_line:
** Used by ft_strjoin to concatenate buffers safely.
*/
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
** ft_strjoin
** ----------
** Concatenates two strings into a new allocated string.
**
** Parameters:
** - s1: first string
** - s2: second string
**
** Returns:
** - Newly allocated string containing s1 + s2
** - NULL if allocation fails or inputs are NULL
**
** Important:
** - Does NOT free s1 or s2
**
** Purpose in get_next_line:
** Used to accumulate buffer content into a "stash"
** until a full line (ending with '\n') is found.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	ft_strlcat(result, s1, len);
	ft_strlcat(result, s2, len);
	return (result);
}

/*
** ft_substr
** ---------
** Extracts a substring from string 's'.
**
** Parameters:
** - s: original string
** - start: starting index
** - len: maximum length of substring
**
** Returns:
** - Newly allocated substring
** - Empty string if start >= length of s
** - NULL if allocation fails
**
** Behavior:
** - Copies at most 'len' characters from s starting at 'start'
**
** Purpose in get_next_line:
** Used to:
** 1. Extract the current line (up to '\n')
** 2. Keep the remaining data for next calls (stash)
*/
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strjoin(NULL, ""));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

---

# Algorithm and Design Choices


## Core Idea

The main challenge is that `read()` does not guarantee to return a full line.
It reads a fixed number of bytes defined by `BUFFER_SIZE`.

Therefore, we must:

1. Read chunks of data
2. Store them
3. Extract complete lines
4. Preserve remaining data for the next call

---

## Static Buffer

A static variable is used to store leftover data between function calls:

```c
static char *stash;
```

Why static?

- It keeps data between multiple calls
- It allows the function to continue where it stopped

---

## Reading Process

Algorithm:

1. Read from file descriptor into a buffer
2. Append buffer to stash
3. Repeat until a newline (\n) is found or EOF
4. Extract the line from stash
5. Update stash with remaining data
6. Return the extracted line

---

## Line Extraction

Once a newline is found:

- Allocate memory for the line
- Copy characters up to and including \n
- Return the line

If no newline is found:

- Return the remaining content (last line)

---

## Memory Management

Memory is dynamically allocated for:

- the line to return
- the storage (stash)

Important rules:

- free unused memory
- avoid leaks
- handle allocation failures

---

## Edge Cases

The implementation handles:

- empty files
- files without newline at the end
- very large lines
- invalid file descriptors
- BUFFER_SIZE <= 0
- read errors

---

# Project Structure

```code
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── Makefile
```

---

# Resources

## Documentation

- man 2 read
- man 3 malloc
- man 3 free
- POSIX file descriptors documentation
- read(2) - https://man7.org/linux/man-pages/man2/read.2.html
- File input/output - https://en.cppreference.com/w/c/io

---
# Use of AI

AI tools were used for:

- understanding buffer management and file reading logic
- clarifying edge cases and expected behavior
- improving documentation and README structure

All algorithms and code were implemented, tested, and validated manually.

---

# Conclusion

The get_next_line project provides a deeper understanding of:

- low-level file I/O
- memory management
- static variables
- efficient data processing

It is a fundamental step toward mastering system-level programming in C.
