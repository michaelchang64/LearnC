#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// go down n floors, then come back up

void elevator(int n) {
    printf("going down: %d\n", n);

    if (n <= 0)
        printf("at the bottom");
    else
        elevator(n-1);

    printf("going up: %d\n", n);
}

// print numbers from min through max the dumb way lol
// this will eventually run out of stack space
// this is tail-recursive
void reduceAndConquer(int min, int max) {
    if (min > max) {
        return;
    } else {
        printf("%d", min);
        reduceAndConquer(min + 1, max);
    }
}

// iterative version
void reduceAndConquerIterative(int min, int max) {
    start:
        if (min > max) {
            return;
        } else {
            printf("%d", min);
            //reduceAndConquer(min + 1, max);
            min++;
            // max = max
            goto start;
        }
}

// iterative version but better
void reduceAndConquerIterativeWithLoop(int min, int max) {
     
    while(min <= max) {
        printf("%d\n", min);
        min++;
    }
}

void reduceAndConquerReversed(int min, int max) {
    if (min > max) {
        return;
    } else {
        reduceAndConquerReversed(min, max - 1);
        printf("%d\n", min);
    }
}


// this method isn't much different from reduceAndConquer in terms of performance time
// though it doesn't go as deep into stack
void splitAndConquer(int min, int max) {
    if (min>max) {
        return;
    } else if (min == max) {
        printf("%d\n", min);
    } else {
        int mid = (min+max) /2;
        splitAndConquer(min, mid);
        splitAndConquer(mid+1, max);
    }
}


int main(int argc, char ** argv) {
    //reduceAndConquer(0, 10);
    //splitAndConquer(0, 10);
    //rereduceAndConquer(0, 10);
    //reduceAndConquerIterative(0, 10);
    reduceAndConquerIterativeWithLoop(0, 10);
    return 0;
}
