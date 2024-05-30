#!/bin/bash

set -e

g++ -std=c++17 -Wall -Wextra main.cpp MyString.cpp -o ./bin/main

echo ''
echo -e "Compilation \033[32mfinished\033[0m at $(date '+%A %H:%M:%S')"
echo ''
