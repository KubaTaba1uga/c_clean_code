You can share code by putting it in seperate C file.
You need to put the function declarations in seperate .h file.
Include header file in every C file that needs to use the shared code.
Include with "" tells the compiler to look for a header file in the 
same directory as c file.
Compile code with command: gcc <c files to compile>.
