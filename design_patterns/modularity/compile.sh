#!/bin/bash

# Compile lib.c and test.c to produce the test_lib executable
gcc lib.c test.c -o test_lib

# Check if the previous command (gcc) failed
if [ $? -ne 0 ]; then
   echo "Unable to compile test_lib program."
   exit 1
fi

# Compile lib.c and main.c to produce the main executable
gcc lib.c main.c -o main

# Check if the previous command (gcc) failed
if [ $? -ne 0 ]; then
   echo "Unable to compile main program."
   exit 1
fi

echo "main and test_lib compiled succesfully"
