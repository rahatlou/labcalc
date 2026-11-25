#include <stdio.h>

int main() {
    int n = 12;
    int *p;   // puntatore a int

    p = &n;   // p contiene &n
    printf("n vale %d\n", n);
    printf("&n vale %p\n", &n);   // indirizzo di n
    printf("p vale %p\n", p);
    printf("*p vale %d\n", *p);   // valore puntato

    *p = 30;   // scrive dentro n
    printf("dopo: n vale %d\n", n);
    return 0;
}
