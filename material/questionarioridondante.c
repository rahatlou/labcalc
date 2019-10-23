#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
	int risposte[3];
	int i, risp, maxrisp = 0, moda;

	/* inizializzo array */
	for (i = 0; i < 3; i++) {
		risposte[i] = 0;		
	}

	/* prima domanda */
	printf("Qual è il tuo colore preferito?\n");
	printf("1. Rosso\n");
	printf("2. Verde\n");
	printf("3. Blu\n");
		
	do {
		scanf("%d", &risp);
		
		if (risp < 1 || risp > 3) {
			printf("%d Spiacente, inserisci un numero tra 1 e 3\n", risp);
		}
	} while (risp < 1 || risp > 3);
	
	risposte[risp]++;
	
	if (risposte[risp] > maxrisp) {
		moda = risp;
		maxrisp = risposte[risp];
	}

	/* seconda domanda */
	printf("Qual è il tuo animale preferito?\n");
	printf("1. Gatto\n");
	printf("2. Cane\n");
	printf("3. Cavallo\n");
		
	do {
		scanf("%d", &risp);
		
		if (risp < 1 || risp > 3) {
			printf("%d Spiacente, inserisci un numero tra 1 e 3\n", risp);
		}
	} while (risp < 1 || risp > 3);
	
	risposte[risp]++;

	if (risposte[risp] > maxrisp) {
		moda = risp;
		maxrisp = risposte[risp];
	}

	/* terza domanda */
	printf("Qual è la tua bevanda preferita?\n");
	printf("1. Vino\n");
	printf("2. Birra\n");
	printf("3. Aranciata\n");
		
	do {
		scanf("%d", &risp);
		
		if (risp < 1 || risp > 3) {
			printf("%d Spiacente, inserisci un numero tra 1 e 3\n", risp);
		}
	} while (risp < 1 || risp > 3);
	
	risposte[risp]++;

	if (risposte[risp] > maxrisp) {
		moda = risp;
		maxrisp = risposte[risp];
	}

	/*do l'output*/
	printf("Maggioranza di risposte %d\n", moda);
	
	switch (moda) {
		case 1:
			printf("Sei una persona vivace!\n");
			break;

		case 2:
			printf("Sei una persona interessante!\n");
			break;

		case 3:
			printf("Sei una persona noiosa!\n");
			break;
	}	

	return 0;
}
