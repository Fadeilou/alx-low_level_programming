#!/bin/bash

echo '#include <stdlib.h>' > /tmp/rand.c
echo '#include <time.h>' >> /tmp/rand.c
echo '#include <unistd.h>' >> /tmp/rand.c
echo '__attribute__((constructor)) void init(void) { srand(time(NULL) + getpid()); }' >> /tmp/rand.c
echo 'int rand(void) { return 9; }' >> /tmp/rand.c
gcc -Wall -fPIC -shared -o /tmp/rand.so /tmp/rand.c
export LD_PRELOAD=/tmp/rand.so
