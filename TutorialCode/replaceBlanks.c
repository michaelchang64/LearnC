#include <stdio.h>

#define     NONBLANK ('a')

// replace string of blanks with single blank

main() {
    int c, lastC;
    
    lastC = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        } else if (c == ' ') {
            if (lastC != ' ') {
                putchar(c);
            }     
        }
        lastC = c;  
    }
}
