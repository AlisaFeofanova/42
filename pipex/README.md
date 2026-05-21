*This project has been created as part of the 42 curriculum by alfeofan.*

# pipex

## Description

**pipex** is a project from the 42 curriculum focused on understanding how UNIX pipes, process creation, and file descriptor redirection work.

The goal is to recreate the shell behavior of commands connected with pipes, such as:

```bash
< infile cmd1 | cmd2 > outfile
```

The program takes an input file, executes two shell commands connected through a pipe, and writes the final result into an output file.

Example:

```bash
./pipex infile "grep hello" "wc -l" outfile
```

Equivalent shell command:

```bash
< infile grep hello | wc -l > outfile
```

This project introduces important low-level UNIX concepts including:

- process creation with `fork()`
- inter-process communication with `pipe()`
- file descriptor duplication with `dup2()`
- program execution with `execve()`
- process synchronization with `wait()` / `waitpid()`

---

## Features

### Mandatory
- Input redirection from file
- Output redirection to file
- Execution of two commands
- Pipe connection between commands
- PATH resolution
- Error handling

### Bonus (if implemented)
- Multiple pipes
- `here_doc`

---

## Project Structure

```bash
pipex/
├── Makefile
├── includes/
│   └── pipex.h
├── src/
│   ├── main.c
│   ├── exec.c
│   ├── path.c
│   ├── utils.c
│   └── error.c
└── libft/
```

---

## Instructions

### Compilation

Clone repository:

```bash
git clone <repository_url>
cd pipex
```

Compile project:

```bash
make
```

Available rules:

```bash
make        # compile
make clean  # remove object files
make fclean # remove object files and executable
make re     # rebuild project
```

---

### Execution

Run:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex input.txt "cat" "wc -l" output.txt
```

Equivalent to:

```bash
< input.txt cat | wc -l > output.txt
```

---

## Technical Concepts

This project helped practice:

- UNIX system calls
- process management
- file descriptor manipulation
- shell command execution
- environment variables (`PATH`)
- memory management and cleanup

Key functions used:

- `open`
- `close`
- `read`
- `write`
- `malloc`
- `free`
- `access`
- `dup`
- `dup2`
- `fork`
- `pipe`
- `execve`
- `wait`
- `waitpid`

---

## Resources

### Documentation

- Piping in Unix or Linux
  https://www.geeksforgeeks.org/linux-unix/piping-in-unix-or-linux/

- Understand pipex
  https://42-cursus.gitbook.io/guide/2-rank-02/pipex/understand-pipex

- Pipex the 42 project “Understanding Pipelines in C”
  https://medium.com/@omimouni33/pipex-the-42-project-understanding-pipelines-in-c-71984b3f2103

- pipex tutorial — 42 project
  https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901

- Introducing Pipes
  https://www.rozmichelle.com/pipes-forks-dups/?source=post_page-----71984b3f2103---------------------------------------#pipelines







- Linux manual pages  
  https://man7.org/linux/man-pages/

- pipe(2)  
  https://man7.org/linux/man-pages/man2/pipe.2.html

- fork(2)  
  https://man7.org/linux/man-pages/man2/fork.2.html

- dup2(2)  
  https://man7.org/linux/man-pages/man2/dup.2.html

- execve(2)  
  https://man7.org/linux/man-pages/man2/execve.2.html

---

### Tutorials & Articles
- Beej's Guide to UNIX IPC  
  https://beej.us/guide/bgipc/

- Advanced Programming in the UNIX Environment  
  W. Richard Stevens

---

### AI Usage

AI tools were used as learning assistance during development.

Used for:
- explaining how pipes and file descriptors work
- understanding process flow with `fork()`, `pipe()`, and `execve()`
- reviewing project structure ideas
- README formatting and documentation writing

AI was **not used to directly submit generated code without understanding or adaptation**.

---

## Notes

This project is part of the 42 school curriculum and is intended for educational purposes in UNIX programming and systems development.
