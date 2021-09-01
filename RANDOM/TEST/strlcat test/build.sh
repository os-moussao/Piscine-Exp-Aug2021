#!/bin/sh
gcc -Wall -Werror -Wextra $1 main2.c -o ft.out
gcc -Wall -Werror -Wextra $1 main.c -o std.out
./std.out
./ft.out
