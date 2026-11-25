#include <stdio.h>

int main() {
    int v[3] = {4, 9, 2};
    int i;

    // indici validi: 0, 1, 2
    for (i = 0; i < 5000; i++) {
        v[i] = 0;
    }
    printf("fatto\n");
    return 0;
}
