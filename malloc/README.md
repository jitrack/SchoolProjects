# malloc

Rewrite the 4 following C library functions: malloc, free, realloc and calloc.

We can only use brk/sbrk system call

Do not even think about using the malloc function.
Your function prototypes must be the same as the ones from the C library, and must be contained in the
library compiled by your Makefile.
void *malloc(size_t size);
void *realloc(void *ptr , size_t size);
void free(void *ptr);
void *calloc(size_t size, size_t nb);

USAGE :

./LD_PRELOAD=./libmy_malloc.so {command}

EXAMPLE :

./LD_PRELOAD=./libmy_malloc.so ./ls

./LD_PRELOAD=./libmy_malloc.so ./ls -R
