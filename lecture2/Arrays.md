## Clang
clang is a compiler and if you dont using the cs50 enviroment to write code, the code bellow will help you 
```
clang hello.c -o hello -lcs50
```

it be equivalent to 
```
make hello
```

## Compile 

* preprocessing 
hash files at the top of code (prototype)

* compiling 
assembly computer instructions 

* assembling 
from assembly to 0's and 1's 

* linking
link the binaries of cs50.c and hello.c to a unic file call hello

## Debug 

program step by step to know, line by line, what the code is doing 

## Types

bool    | 1 byte
char    | 1 byte 
double  | 8 bytes
float   | 4 bytes
int     | 4 bytes
long    | 8 bytes 
string  | ? bytes

## Memory 

RAM (Random Access Memory) is where the 0's and 1's are stored, or rather, they are stored while your program is running.

## Array 

is a collection of elements of the same type, placed in contiguous memory locations that can be indidually referenced by using a index to a unique idenfifier

## string

in c is a array of chars

## NUL char

is a 00000000, after a string, to computer identify where string end. 
so if inside your string is stored "HI!", actually the string stores "HI!\0"

## command-line Arguments 

is a way to run code, return error messages and automate tests
