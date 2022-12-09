Defined in header <stdlib.h>
```clike
void srand(unsigned seed);
```

Seeds the pseudo-random number generator used by [[rand()]] with the value `seed`.
If `rand()` is used before any calls to `srand()`, `rand()` behaves as if it was seeded with `srand(1).

Each time `rand()` is seeded with the same `seed`, it must produce the same sequence of values.

`srand()` is not guaranteed to be thread-safe.

### Parameters
Seed - the seed value

### Return value
(none).

### Notes
Generally speaking, the pseudo-random number generator should only be seeded once, before any calls to `rand()`, and the start of the program. It should not be repeatedly seeded, or reseeded every time you wish to generate a new batch of pseudo-random numbers.

Standard practice is to use the result of a call to `time(0)` as the seed. However, `time()` returns a [[time_t]] value, and `time_t` is not guaranteed to be an integral type. In practice, though, every major implementation defines `time_t` to be an integral type, and this is also what POSIX requires.

### Example
```clike
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    srand(time(NULL)); //use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);
}
```

Possibile output:
```clike
Random value on [0 2147483647]: 1373858591
```

