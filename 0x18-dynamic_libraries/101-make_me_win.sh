#!/bin/bash

echo -e '#include <stdlib.h>\n#include <time.h>\n#include <unistd.h>\n__attribute__((constructor)) void init(void) { srand(time(NULL) + getpid()); }\nint rand(void) { return 9; }' > /tmp/rand.c
gcc -Wall -fPIC -shared -o /tmp/rand.so /tmp/rand.c
export LD_PRELOAD=/tmp/rand.so
