#include <stdio.h>

#define IN  (1) //in the word
#define OUT (0) //out of the word

main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (state == IN) {
                putchar('\n');  //finish the word
                state = OUT;
            }
        } else if (state == OUT) {
            state = IN;
            putchar(c);
        } else {
            putchar(c);
        }
    }
}
