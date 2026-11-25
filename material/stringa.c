#include <stdio.h>

int main() {
    char particella[10] = "muone";
    int i;

    for (i = 0; i < 6; i++) {
        printf("%d ", particella[i]);  // codici ASCII
    }
    printf("\n");
    printf("%s\n", particella);  // fino al \0

    particella[3] = '\0';  // \0 in mezzo
    printf("%s\n", particella);

    printf("%p\n", particella);       // il nome da solo
    printf("%p\n", &particella[0]);   // la prima casella
    printf("%c\n", *particella);      // il suo contenuto
    return 0;
}
