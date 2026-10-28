#include <stdio.h>
#define NMAX 30

int main() {
    FILE *fp;
    int n;
    unsigned long long a0 = 0, a1 = 1, an;  // F(0), F(1)
    fp = fopen("dati/fibonacci.txt", "w"); // non esiste
    for (n = 1; n <= NMAX; n++) {
        an = a0 + a1;                        // F(n+1)
        fprintf(fp, "%d %llu %.6f\n", n, a1, (double) an / a1);
        a0 = a1;
        a1 = an;
    }
    fclose(fp);
}
