Defined in header <stdlib.h>
```clike
#define RAND_MAX /* implementation defined */
```

Expands to an integer constant expression equal to the maximum value returned by the function [[rand()]] This value is implementation dependent. It's guaranteed that this value is at least `32767`.

### Example
```clike
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	// use current time as seed for random
	srand(time(NULL))
	printf("RAND_MAX: %i\n", RAND_MAX);
	printf("INT_MAX: %i\n", INT_MAX);
	printf("Random value on [0, 1]: %f\n", (double)rand() / RAND_MAX);
}
```

Possible output:
```clike
RAND_MAX: 2147483647
INT_MAX: 2147483647
Random value on [0,1]: 0.362509
```
