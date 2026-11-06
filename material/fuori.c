#include <stdio.h>

int main() {
    int a[3] = {10, 20, 30};
    int i;
    for (i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}
