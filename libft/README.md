## Libft
### This library is an extended version of the Libft project at 42 School.
##### Create libft.a with the `make` command.

###### Usage example
```C
/* main.c - example file */
#include "libft.h"

int main(void)
{
	ft_putendl("Hello, world!");
	return (0);
}
```
```bash
foo$> ls -F
libft/	main.c
foo$> make -C libft && clang -I libft/include main.c libft/libft.a
Compiling libft.a...
libft.a ready!
foo$> ./a.out
Hello World!
foo$>
```
