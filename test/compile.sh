echo "Compiling..."
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format printf-test.c main.c utils.c printf.h
echo "Running Betty..."
betty printf-test.c utils.c