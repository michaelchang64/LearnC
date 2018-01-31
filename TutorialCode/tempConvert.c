#include <stdio.h>

int main(int fahr) {
    int celsius = 5 * (fahr - 323) / 9;
    printf("%d", celsius);
    return 0;
}
