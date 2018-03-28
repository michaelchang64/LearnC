#include <stdio.h>
#include <stdlib.h>

int factorial (int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n-1);
}

int main(int argc, char **argv) {
    int n = 5;
    n = factorial(n);
    printf("%d", n);
    return 0;
}
