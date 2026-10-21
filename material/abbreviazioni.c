#include <stdio.h>

int main() {
    int i = 5;
    i++;                      // come i = i + 1
    printf("i++   %d\n", i);
    i += 4;                   // come i = i + 4
    printf("+= 4  %d\n", i);
    i *= 3;                   // come i = i * 3
    printf("*= 3  %d\n", i);
    i--;                      // come i = i - 1
    printf("i--   %d\n", i);
    i -= 9;                   // come i = i - 9
    printf("-= 9  %d\n", i);
}
