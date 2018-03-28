#include <stdio.h>

main() {
    double counterBlank, counterTab, counterLine, c;

    counterBlank = 0;
    counterTab = 0;
    counterLine = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++counterTab;
        else if (c == '\n')
            ++counterLine;
        else if (c == ' ')
            ++counterBlank;
    }
    printf("# of tabs: %.0f\n# of lines: %.0f\n# of blanks: %.0f\n", counterTab, counterLine, counterBlank);
}
