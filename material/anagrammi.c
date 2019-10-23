#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

#define MAXLUNG 6
#define MAXPERM 720

void scambia (char v[], int i, int j);
void permuta (char anagrammi[][MAXLUNG+1], int* corrente, char v[], int n, int i);
int fattoriale (int n);

int main() {
	char parola[100] = "";
	int lunghezza, permutazioni, i, corrente = 0;
	char anagrammi[MAXPERM][MAXLUNG+1];

	do {
		printf("Inserisci la parola da anagrammare, di massimo %d lettere\n", MAXLUNG);
		scanf("%s", parola);

		lunghezza = (int) strlen(parola);
	} while (lunghezza > MAXLUNG);

	permutazioni = fattoriale(lunghezza);
	
	printf("Esistono %d permutazioni di %s:\n", permutazioni, parola);

	permuta(anagrammi, &corrente, parola, lunghezza, 0);

	for (i = 0; i < corrente; i++)
		printf("%d\t%s\n", i + 1, anagrammi[i]);

	printf("Le altre %d permutazioni erano ripetute\n", permutazioni - corrente);

	return 0;
}

void scambia (char v[], int i, int j) {
	char t;
	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void permuta (char anagrammi[][MAXLUNG+1], int* corrente, char v[], int n, int i) {
	int j, copia, scorri;

	if (i == n) {
		for (scorri = 0; scorri < *corrente; scorri++)
			if (strcmp(anagrammi[scorri], v) == 0)
				return;

		for (copia = 0; copia <= n; copia++)
			anagrammi[*corrente][copia] = v[copia];

		(*corrente)++;
	} else {
		for (j = i; j < n; j++) {
			scambia (v, i, j);
			permuta (anagrammi, corrente, v, n, i + 1);
			scambia (v, i, j);
		}
	}
}

int fattoriale(int n) {
	if (n < 2)
		return 1;

	return fattoriale(n - 1) * n;
}
