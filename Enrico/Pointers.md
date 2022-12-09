Memory (RAM):
1 byte
|     ↑    |   ↑                      a int 204
|            |  209  } -> c         c char 209
|            |  208
|            |  207 +
|            |  206  } -> a
|            |  205  |
|            |  204 +
|            |  203 
|            |  202
|            |  201
|     ↓    |   ↓
			    0	

int - 4 bytes
char - 1 byte
float - 4 bytes

```clike
int a;
char c;
a = 5
...
...
a++;
```

### Pointers
Variables that store address of another variable

Memory 
208 |   b = 10 |  
204 |  a = 5    |  <-----+
       |               |               |
       |               |               |
       |               |               |
       |               |               |
  64 | P = 204 | --------+

```clike
int a;
// P is a pointer variable that points to an integer
int *P;
// Ampersand gives us the address of the variable a
P = &a;
a = 5;
printf P; // output: 204
printf  &a; // output: 204
printf &P; // output: 64
printf *P; // the value of the localtion that it points to. Output: 5 -> Derefrencing
*P = 8
print a // output: 8
```

