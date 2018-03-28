#include <stdio.h>

//count chars in input, version 1

main() {
    long nc;

    nc = 0;
    while (getchar() != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);
}
