Copyright Szabo Cristina-Andreea
# Mini Libc

## Overview

Mini Libc is an implementation of a subset of standard C library functionalities, designed for freestanding environments that avoid external dependencies on a full libc. This project provides essential system calls, memory management, string manipulation, file I/O operations, and sleep functions, tailored for low-level systems programming or embedded system development.

## Features

- **String Manipulation**:  
  Implements essential string functions, including:
  - `strcpy()`: Copy strings.
  - `strcat()`: Concatenate strings.
  - `strlen()`: Calculate the length of a string.

- **Memory Allocation**:  
  Provides basic memory management:
  - `malloc()`: Allocate memory.
  - `free()`: Free allocated memory.
  - `mmap()`: Memory mapping for advanced memory management.

- **POSIX-Compliant File I/O**:  
  Includes fundamental file I/O operations:
  - `open()`: Open files for reading or writing.
  - `close()`: Close open files.
  - `lseek()`: Seek to a specific position within a file.

- **Sleep Functions**:  
  Implements time-related functions:
  - `sleep()`: Pause execution for a specified number of seconds.
  - `nanosleep()`: Pause execution for a specified duration in nanoseconds.

- **Freestanding Implementation**:  
  The library is designed to work without relying on an external C standard library. It is suitable for environments like operating systems or embedded systems where minimal dependencies are crucial.

## Project Structure

- **Makefile**: The build script for compiling the project.
- **errno.c**: Implements error handling, defining the `errno` variable for error tracking.
- **syscall.c**: Contains the system call interface, allowing interaction with the kernel.
- **string**: Implements basic string manipulation functions like `strcpy`, `strcat`, and `strlen`.
- **mm**: Provides memory allocation functions like `malloc`, `free`, and `mmap`.
- **process**: Manages process-related system calls.
- **io**: Implements basic I/O operations such as `open`, `close`, and `lseek`.

