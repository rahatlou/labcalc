#include <stdio.h>

int main() {
    printf("char        %zu byte\n", sizeof(char));
    printf("short       %zu byte\n", sizeof(short));
    printf("int         %zu byte\n", sizeof(int));
    printf("long        %zu byte\n", sizeof(long));
    printf("long long   %zu byte\n", sizeof(long long));
    printf("float       %zu byte\n", sizeof(float));
    printf("double      %zu byte\n", sizeof(double));
    printf("long double %zu byte\n", sizeof(long double));
}
