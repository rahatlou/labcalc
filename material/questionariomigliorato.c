#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

void domanda(char* mess, char* risp1, char* risp2, char* risp3, int risposte[], int* maxrisp, int* moda);

int main() {
	int risposte[3];
	int i, maxrisp = 0, moda;

	/* inizializzo array */
	for (i = 0; i < 3; i++) {
		risposte[i] = 0;		
	}

	/* prima domanda */
	domanda("Qual è il tuo colore preferito?", "Rosso", "Verde", "Blu", risposte, &maxrisp, &moda);		

	/* seconda domanda */
	domanda("Qual è il tuo animale preferito?", "Gatto", "Cane", "Cavallo", risposte, &maxrisp, &moda);

	/* terza domanda */
	domanda("Qual'è la tua bevanda preferita?", "Vino", "Birra", "Aranciata", risposte, &maxrisp, &moda);

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

void domanda(char* mess, char* risp1, char* risp2, char* risp3, int risposte[], int* maxrisp, int* moda) {
		
	int risp;

	printf("%s\n", mess);
	printf("1. %s\n", risp1);
	printf("2. %s\n", risp2);
	printf("3. %s\n", risp3);
		
	do {
		scanf("%d", &risp);
		
		if (risp < 1 || risp > 3) {
			printf("%d Spiacente, inserisci un numero tra 1 e 3\n", risp);
		}
	} while (risp < 1 || risp > 3);
	
	risposte[risp]++;

	if (risposte[risp] > *maxrisp) {
		*moda = risp;
		*maxrisp = risposte[risp];
	}

}
