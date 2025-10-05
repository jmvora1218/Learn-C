#!/bin/bash -x


set -e

gcc a.c -o a


rm a.db


./a a.db c
./a a.db s 23 jayd jay@d
./a a.db s 24 jayv jay@v
./a a.db s 23 xxyy xxyy


./a a.db l


