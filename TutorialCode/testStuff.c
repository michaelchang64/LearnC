#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int division(int a, int b) {
    //what should happen in the following code is returning the rounded down result of the division
    return a / b;
}

int main(int argc, char **argv) {
    int a, b;

    a = 5;
    b = 9;
    printf("%d divided by %d is %d\n", a, b, division(a, b));

    return 0;
}
