#include <TEST.h>
static int cnt = 0;

void print_prefix(char *prefix)
{
    printf("\33[0;32m%s\33[0m", prefix);
}

void assertTrue(int (*foo)(char *))
{
    char buf[50];
    int res = foo(buf);
    if (res == TRUE)
        printf("\33[0;33m%s\33[0m \33[0;32mtest %d succeeded.\33[0m\n", buf, ++cnt);
    else
        printf("\33[0;33m%s\33[0m \33[0;31mtest %d failed. Expected: %d, Actual: %d. \33[0m\n", buf, ++cnt, 1, res);
}

void assertFalse(int (*foo)(char *))
{
    char buf[50];
    int res = foo(buf);
    if (res == FALSE)
        printf("\33[0;33m%s\33[0m \33[0;32mtest %d succeeded.\33[0m\n", buf, ++cnt);
    else
        printf("\33[0;33m%s\33[0m \33[0;31mtest %d failed. Expected: %d, Actual: %d. \33[0m\n", buf, ++cnt, 0, res);
}

void assertBoolean(int (*foo)(char *), int value)
{
    char buf[50];
    int res = foo(buf);
    if (res == value)
        printf("\33[0;33m%s\33[0m \33[0;32mtest %d succeeded.\33[0m\n", buf, ++cnt);
    else
        printf("\33[0;33m%s\33[0m \33[0;31mtest %d failed. Expected: %d, Actual: %d. \33[0m\n", buf, ++cnt, value, res);
}

void assertInt(int (*foo)(char *), int value)
{
    char buf[50];
    int res = foo(buf);
    if (res == value)
        printf("\33[0;33m%s\33[0m \33[0;32mtest %d succeeded.\33[0m\n", buf, ++cnt);
    else
        printf("\33[0;33m%s\33[0m \33[0;31mtest %d failed. Expected: %d, Actual: %d. \33[0m\n", buf, ++cnt, value, res);
}