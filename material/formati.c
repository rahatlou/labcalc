#include <stdio.h>

int main() {
    double x = 12345678.123456789;
    double y = 0.0001234567;
    printf("formato x\t\ty\n");
    printf("%%f      %f\t%f\n", x, y);
    printf("%%5.3f   %5.3f\t%5.3f\n", x, y);
    printf("%%5.3e   %5.3e\t%5.3e\n", x, y);
    printf("%%5.3g   %5.3g\t%5.3g\n", x, y);
    printf("%%.15f   %.15f\t%.15f\n", x, y);
}
