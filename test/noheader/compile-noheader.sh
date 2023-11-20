echo "Compiling..."
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format printf-noheader.c
echo "Running Betty..."
betty printf-noheader.c