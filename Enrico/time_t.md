Defined in header <time.h>
```clike
typefed /* unspecified */ time_t;
```

Although not defined by the C standard, this is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to [POSIX time](https://en.wikipedia.org/wiki/Unix_time "enwiki:Unix time").

### Notes
The standard uses the term _calendar time_ when referring to a value of type `time_t`.

### Example
Show the start of the epoch
```clike
#include <stdio.h>
#include <time.h>
#include <stdint.h>
 
int main(void)
{
    time_t epoch = 0;
    printf("%jd seconds since the epoch began\n", (intmax_t)epoch);
    printf("%s", asctime(gmtime(&epoch)));
}
```

Possible output:
```clike
0 seconds since the epoch began
Thu Jan  1 00:00:00 1970
```
