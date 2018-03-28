#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int a0, int a1, int a2, int b0, int b1, int b2){
    int aP = 0;
    int bP = 0;
    int *arrA = malloc(sizeof(*arrA) * 3);
    int *arrB = malloc(sizeof(*arrB) * 3);

    arrA[0] = a0;
    arrA[1] = a1;
    arrA[2] = a2;

    arrB[0] = b0;
    arrB[1] = b1;
    arrB[2] = b2;

    for (int i = 0; i < 3; i++) {
        if (arrA[i] > arrB[i]){
            aP++;
        } else if (arrA[i] < arrB[i]) {
            bP++;
        } else {
        }
    }
    int *result_size = malloc(sizeof(*result_size) * 2);
    result_size[0] = aP;
    result_size[1] = bP;

    return result_size;
}

int main(int argc, char **argv) {
    int a0 = 0;
    int a1 = 1;
    int a2 = 2;
    int b0 = 1;
    int b1 = 2;
    int b2 = 3;
    int* result = solve(a0, a1, a2, b0, b1, b2);
    for(int i = 0; i < 2; i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    puts("");

    return 0;
}

// int main(int argc, char **argv) {
//     int a0;
//     int a1;
//     int a2;
//     scanf("%d %d %d", &a0, &a1, &a2);
//     int b0;
//     int b1;
//     int b2;
//     scanf("%d %d %d", &b0, &b1, &b2);
//     int result_size;
//     int* result = solve(a0, a1, a2, b0, b1, b2, &result_size);
//     for(int result_i = 0; result_i < result_size; result_i++) {
//         if(result_i) {
//             printf(" ");
//         }
//         printf("%d", result[result_i]);
//     }
//     puts("");
//
//
//     return 0;
// }
