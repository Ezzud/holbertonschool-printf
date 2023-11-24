# Printf

## Description

This project is a recreation of the printf function in C, including its most important features & formatting options.

## How to use
You can call the **_printf()** function:
```
#include "main.h"

int main() 
{
    _printf("This is a text");
    return (0);
}
```

## Manual

You can access to the man page by using:
```
$ man ./man_3_printf
```

## Formatting

You can use a format indicator to integrate a variable in your text to print, here is the list of the available formats: 

| Format  | Typedef | Description |
| ------------- |:-------------:|:-------------:|
| %d      | int    | Print a decimal number  |
| %i      | int    | Print a decimal number  |
| %c      | int/char    | Print a char OR convert an int to his char value  |
| %s      | char * | Print a string  |
| %u      | int    | Print a positive decimal number  |
| %b      | int    | Convert and print number to his binary value  |
| %o      | int    | Print a positive decimal number as an octal number  |
| %x      | int    | Convert and print number to Hexadecimal (lowercase)  |
| %X      | int    | Convert and print number to Hexadecimal (uppercase)  |
| %%      |    | Print the character '%'  |

### Example:

The following code:
``` 
#include "main.h"

int main()
{
    _printf("Best %s", "School");
    return (0);
}
```
Will result (after compilation) as an output:
```
$ ./a.out
Best School
```

## Flowchart

![Flowchart](https://raw.githubusercontent.com/Ezzud/holbertonschool-printf/main/static/flowchart.svg)
