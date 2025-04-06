#pragma once

char* getlinesdyn();
char* fgetsdyn();

/** 
 * -------- (Since I will probably forget) ---------
 * Compiling for your program or makefile... (By me!!)
 * -> Temp and short description of how to compile for 
 * -> .c to be included in other files
 * ------------ Static Library approach ----------
 * -- Navigate to custom_files directory (if not made, make)
 * cd custom_files
 * 
 * -- Compile c file, use "-c" flag to compile source but not make executable
 * gcc -c fname.c -o fname.o
 * 
 * -- Create archive via "ar", "rcs" for replace existing, create ar, create index
 * -- next part is lib<name>.a for library naming, and include the previously compile files
 * ar rcs libstrinputs.a str_inputs.o
 * 
 * -- navigate back
 * cd executable_dir
 * 
 * -- compile executable with path to search for library using "-L" flag
 * -- "-l" will link via appending lib and .a to name as seen in "lib<name>.a"
 * gcc executable.c -L../custom_files -l[library_name] -o program
 * 
 * Note... Can add multiple obj files to a single library
 * Example: 
 * gcc -c file1.c -o file1.o
 * gcc -c file2.c -o file2.o
 * ar rcs libmylib.a file1.o file2.o
 * */