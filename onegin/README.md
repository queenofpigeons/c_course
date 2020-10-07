# Hamlet sort

## Project description
Program sorts a .txt file by comparing aplpha symbols and ignoring all others. There are two available modes: linear and reverse, the latter compares lines starting from the end of the line.

Program takes an input of a Hamlet.txt file and outputs hamlet_original.txt and either hamlet_sorted.txt or hamlet_reverse_sorted.txt depending on the mode

____

## Getting started
### Deps
- gcc
- cmake
- (optional) doxygen
### Building
To build the program cd to the working directory and run
```
make
```
To remove all the built files use
```
make clean
```
Note that this command does not remove sorted .txt files
### Running
Use
```
./run path/to/hamlet.txt
```
to run the program.
You can use the -r option to choose to run it in reverse comparison mode

### Testing
Use
```
./run -t path/to/hamlet.txt
```
to run tests before sorting the original file
