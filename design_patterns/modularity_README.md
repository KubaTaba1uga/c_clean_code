
## lib.h
```
#pragma once

typedef struct
{
    void (*doFoo)(int x);
    const char *(*doBar)(void *p);
} YourApi;

extern const YourApi yourApi;
```

## lib.c
```
#include "lib.h"

#include <stdio.h>

static void doFoo(int x)
{
    printf("Doing foo %d\n", x);
}

static const char *doBar(void *p)
{
    printf("Doing bar: %p\n", p);
    return "Hello";
}

const YourApi yourApi = {
    doFoo,
    doBar};
```

## Harness
```
#include "lib.h"

int main()
{
    yourApi.doFoo(42);
    yourApi.doBar("asd");
}
```

## Summary
The static keyword limits the scope to the translation unit so it won't collide with others.

The user can then shorten it by using a pointer like YourApi *ya = &yourApi, then using ya->doFoo(...).

It also provides a nice way to mock your library for testing.
