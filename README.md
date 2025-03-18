# MiniShell

MiniShell is a minimal, custom-built shell for Unix-like systems, designed to execute built-in commands, manage external processes, and support input/output redirection and pipelines. This shell mimics basic shell functionalities, supporting common operations such as executing commands, file redirection, and process management. It also includes support for parallel and conditional execution of commands.

## Features

- **Built-in Commands**:
  - `cd <directory>`: Changes the current working directory.
  - `pwd`: Prints the current working directory.
  - `exit`: Exits the shell.
  
- **Environment Variable Support**: Support for environment variables like `$HOME`, `$PATH`, etc.

- **Execution of External Commands**: Commands that are not built-in are executed using `execvp()`, with support for argument passing, variable expansion and execution of any valid external commands like `ls`, `cat`, `echo`, etc.

- **Input & Output Redirection**:
  - `< file`: Reads input from a file.
  - `> file`: Redirects output to a file (overwrites the file).
  - `>> file`: Appends output to a file.

- **Piping** (`|`): Allows output from one command to be used as input for another. Implemented using anonymous pipes (`pipe()` and `dup2()`).

- **Parallel Execution** (`&`): Runs multiple commands simultaneously. Implemented using `fork()` and waits for child processes to finish using `waitpid()`.

- **Conditional Execution** (`&&`, `||`):
  - `&&`: Executes the second command only if the first command succeeds.
  - `||`: Executes the second command only if the first command fails.
