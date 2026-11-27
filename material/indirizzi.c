#include <stdio.h>

int main() {
    int v[4] = {3, 8, 5, 1};
    double w[3] = {0.5, 1.5, 2.5};
    int i;

    for (i = 0; i < 4; i++) {
        printf("&v[%d] = %p\n", i, &v[i]);
    }
    for (i = 0; i < 3; i++) {
        printf("&w[%d] = %p\n", i, &w[i]);
    }

    printf("&v[0]  = %p\n", &v[0]);
    printf("v      = %p\n", v);              // il nome dell'array
    printf("*v     = %d\n", *v);             // come v[0]

    printf("&v[2]  = %p\n", &v[2]);
    printf("v + 2  = %p\n", v + 2);          // 2 caselle avanti
    printf("*(v+2) = %d\n", *(v + 2));       // come v[2]
    printf("*(v+1) = %d\n", *(v + 1));       // come v[1]
    printf("(*v)+1 = %d\n", (*v) + 1);       // come v[0] + 1
    return 0;
}
