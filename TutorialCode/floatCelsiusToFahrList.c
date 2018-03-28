#include <stdio.h>

main(int argc, char **argv) {
    float celsius, fahr;
    int lower, upper, step;
    
    lower = 0;
    upper = 100;
    step = 10;

    celsius = lower;
    printf("%7s %4s\n", "celsius", "fahr");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%4.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
