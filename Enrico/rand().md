Defined in header <stdlib.h>
```clike
int rand();
```

[[srand()]] seeds the pseudo-random number generator used by `rand()`. If `rand()` is used before any calls to `srand()`, `rand()` behaves as if it was seeded with `srand(1)`. Each time `rand()` is seeded with `srand()`, it must produce the same sequence of values.

### Parameters
(none).

### Return value
A pseudo-random integer value between 0 and [[RAND_MAX]], inclusive

### Notes
There are no guarantees as to the quality of the random sequence produced. In the past, some implementations of `rand()` have had serious shortcomings in the randomness, distribution and period of the sequence produced. `rand()` is not recommended for serious random-number generation needs, like cryptography.

### Example
```clike
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{ 
    // use current time as seed for random generator
	srand(time(NULL));
	
	int random_variable = rand();
	printf("Random value on [0, %d]: %d\n", RAND_MAX, random_variable);

	// rool a 6-sided die 20 times
	for(int n = 0; n != 20; ++n)
	{
		int x = 7;
		while(X > 6)
		    // Note: 1 + rand() % 6 is biased
			x = 1 + rand() / (RAND_MAX + 1u) / 6)
	}
}
```

Possible output:
```clike 
Random value on [0,2147483647]: 448749574
3 1 3 1 4 2 2 1 3 6 4 4 3 1 6 2 3 2 6 1 
```
