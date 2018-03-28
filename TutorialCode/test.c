#include <stdio.h>
#include <stdlib.h>

/* doesn't work */
void doubler(int x) {
    x *= 2;
}

/* this works lol */
void adding(int *a) {
    *a += 2;
}

// this function basically allows you to cast away the const in the param
void printPointerTarget(const int *p) {
    *((int *) p) = 5; /* no compile-time error */
    printf("%d\n", *p);
}


int main(int argc, char ** argv) {
    int a = 1;
    int *b = &a;

    //adding(&a);
    a++;
    printf("%d\n", a);
    printf("%d\n", *b);
    
    // b--; <- this decrements the pointer thing itself, which causes undefined behavior
    (*b)--; // essential to wrap *b around parens because assignment ops take precedence
    printf("%d\n", a);
    printf("%d\n", *b);

    adding(&a);
    printf("%d\n", a);
    printf("%d\n", *b);
    
    // adding(a); <- this is a nono because not adding the address is a direct pointer to variable assignment
    // like, think of it as basically:
    // int *a = a; X this is bad, doesn't work m8
    adding(b); //with pointers I guess you can just do int *a = b; and it would be fine
    printf("%d\n", a);
    printf("%d\n", *b);
    return 0;
}

