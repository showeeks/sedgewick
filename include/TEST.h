#ifndef __TEST__
#include <stdio.h>
#define TRUE 1
#define FALSE 0
void assertTrue(int (*foo)(char *));
void assertFalse(int (*foo)(char *));
void assertBoolean(int (*foo)(char *), int value);
void assertInt(int (*foo)(char *), int value);
#endif