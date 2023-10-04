
# CIterator

a standalone library i made for use in my transpiler im making but its got nice features such as Generic (but confined) type iterator generation, Ex: 
```c
NewIteratorType(char); // will gen method that return char

NewIteratorType(int); // will gen methods that return int

// both also generate different iterator types :D
```

## Usage

use it however you want just dont steal my code blindly, give some creddit

## Compiling

i included a build scipt (batch) in the repo, while other platforms can compile in theory im not sure, so if you want to compile it i use gcc from w64devkit (really awesome) for most projects and the commands are just compiling the files to objects, then using `ar -rvs OBJECTS.o` where OBJECTS.o is the object file(s) ftom the previous command

How i would compile (without script)

first clone the project and cd into it
```
git clone PLACE_HOLDER

cd CIterator
```

then compile with `-c`
```
gcc -c ./src/CIterator.c -o CIterator.o
```
this outputs the object file

finally we create the static library with
```
ar -rvs ./CIterator.o
```
