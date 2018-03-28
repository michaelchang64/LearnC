#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND (-1)

//return index of key in a[min]..a[max-1]
//or NOT_FOUND if not present
static int binarySearchRange(const int *a, int key, int min, int max) {
    if (max <= min) {
        return NOT_FOUND;
    } else {
        int mid = (min + max) / 2;

        if (a[mid] == key) {
            return mid;
        } else if (a[mid] < key) {
            //somewhere higher up
            return binarySearchRange(a, key, mid+1, max);
        } else {
            //somewhere lower down
            return binarySearchRange(a, key, min, mid);
        }
    }
}

static int binarySearchRangeIterative(const int *a, int key, int min, int max) {
    for(;;) {

        if (max <= min) {
            return NOT_FOUND;
        } else {
            int mid = (min + max) / 2;

            if (a[mid] == key) {
                return mid;
            } else if (a[mid] < key) {
                //somewhere higher up
                //return binarySearchRange(a, key, mid+1, max);
                min = mid + 1;
            } else {
                //somewhere lower down
                //return binarySearchRange(a, key, min, mid);
                max = mid;
            }
        }
    }
}

//return index of key in a,
//or NOT_FOUND if not present
int binarySearch(int n, int *a, int key) {
    return binarySearchRange(a, key, 0, n);
}

int main(int argc, char **argv) {
    if(argc!=1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    int key = atoi(argv[2]);

    int *a = malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        
    }

    int 
    return 0;
}
