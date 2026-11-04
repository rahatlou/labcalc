#include <stdio.h>

int main() {
    int x = 7;          // il seme
    int i;
    for (i = 0; i < 20; i++) {
        printf("%d ", x);
        x = (5 * x + 3) % 16;   // la formula
    }
    printf("\n");
}
