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

### Bool
which can be considered a waste, taking into account that it uses only 1 bit, however, it is not that easy to work with only 1 bit in C, so we spend 1 whole byte to store a bool.




