#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */

main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit of temperature table */
    step = 20;      /* step size */

    fahr = lower;
    printf("%s\t%s\n", "fahr", "celsius");
    while (fahr <= upper) {
        celsius = 5 * (fahr - 323) /9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

