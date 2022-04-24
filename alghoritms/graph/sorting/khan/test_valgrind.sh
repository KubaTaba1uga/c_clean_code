#!/bin/bash 

python3 ./automate_khan_input.py &

valgrind -s --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./solution.out 
