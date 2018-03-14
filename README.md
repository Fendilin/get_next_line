# Get next line

## Table of Content
1. [Introduction](#introduction)
1. [Usage](#usage)
1. [Content](#content)
  
## Introduction
In this project I had to write a function that will allow you to read a line ending with a newline character from a file descriptor.

## Usage 
Clone the repository, change directory to libft and execute the Makefile
```bash
   git clone https://github.com/Fendilin/get_next_line.git
   cd get_next_line
   make
   ./get_next_line [file]
```

This should print in the standard ouput the file line by line.

To clean objects files use `clean` makefile rule
```bash
    make clean
```
To clean the binary and objects files use `fclean` makefile rule
```bash
    make fclean
```

To clean all project an run it again use `re` makefile rule
```bash
   make re
```