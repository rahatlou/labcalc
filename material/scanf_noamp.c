#include <stdio.h>

int main() {
    int n = 12;

    printf("Quanti dadi? ");
    scanf("%d", n);   // manca la &
    printf("n vale %d\n", n);
    return 0;
}
