#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int *a = malloc(sizeof(*a) * 4);
    for (int i = 0; i < 4; i++) {
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
}
