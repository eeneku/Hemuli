#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RODUT 5
#define LUOKAT 5
#define TAIDOT 5
#define EDUT 3
#define OMINAISUUDET 4
#define MERKIT 100
#define EDUT_MAX 20

typedef struct sankari
{
	char nimi[MERKIT];
	int rotu;
	int luokka;
	int edut[EDUT];
	int ominaisuudet[OMINAISUUDET];
} sankari;

void introkuva();
int paavalikko();
int luonti();
int esikatselu(int hahmoID);
int selaus();
void lataus();
void tallennus();
int poisto(int hahmoID);
void pisteet(int hahmoID);
void rodunValinta(int hahmoID);
void luokanValinta(int hahmoID);
void edunValinta(int hahmoID);

void lataaTiedot(char * polku, char * taulukko[], int koko);
void poistaTiedot();

char *rodut[RODUT];
char *luokat[LUOKAT];
char *edut[EDUT_MAX];
char *edutSelitykset[EDUT_MAX];
char *ominaisuudet[OMINAISUUDET];
char *taidot[LUOKAT][TAIDOT];

int rotuArvot[RODUT][OMINAISUUDET] = {
		{ 5, 5, 5, 5 }, 
		{ 4, 6, 7 ,3 }, 
		{ 7, 4, 4, 5},
		{ 8, 5, 3, 4 }, 
		{ 3, 6, 5, 6 }};

sankari * sankarit;
int sankareita = 0;

int main()
{
	lataus();
	int valinta = 0;

	introkuva();
	do
	{
		switch (valinta)
		{
			case 0:
			{
				valinta = paavalikko();
				break;
			}
			case 1:					//Luonti
			{
				valinta = luonti();
				break;
			}
			case 2:					//Selaus
			{
				valinta = selaus();
				break;
			}
			case 3: break;			// Lopetus
		}
	} while (valinta != 3);		// Ohjelman lopetus

	poistaTiedot();

	return 0;
}

void introkuva()
{
	printf("                     _______  _______           _       _________\n");	
	printf("           |\\     /|(  ____ \\(       )|\\     /|( \\      \\__   __/\n");
	printf("           | )   ( || (    \\/| () () || )   ( || (         ) (   \n");
	printf("           | (___) || (__    | || || || |   | || |         | |   \n");
	printf("           |  ___  ||  __)   | |(_)| || |   | || |         | |   \n");
	printf("           | (   ) || (      | |   | || |   | || |         | |   \n");
	printf("           | )   ( || (____/\\| )   ( || (___) || (____/\\___) (___\n");
	printf("           |/     \\|(_______/|/     \\|(_______)(_______/\\_______/\n\n\n");
}

int paavalikko()
{
	int valinta = 0;

	printf("Sankareita: %d\n", sankareita);
	printf("\nHahmoakatemia Hemuli!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	
	while (scanf_s("%d", &valinta) == 0 || valinta < 1 || valinta > 3)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}

	printf("\n");

	system("cls");
	return valinta;
}

int luonti()
{
	sankarit = realloc(sankarit, sizeof(sankari) * ++sankareita);

	int hahmoID = sankareita - 1;
	
	printf("Hahmonluonti!\n\nSy\x94t\x84 hahmon nimi (max. %d merkki\x84. >", MERKIT-1);
	fflush(stdin);
	gets_s(sankarit[hahmoID].nimi, MERKIT);

	system("cls");
	
	rodunValinta(hahmoID);
	
	system("cls");

	luokanValinta(hahmoID);

	printf("\n\nOminaisuudet:\n\n");
	for (int i = 0; i < OMINAISUUDET; i++)
	{
		sankarit[hahmoID].ominaisuudet[i] = rotuArvot[sankarit[hahmoID].rotu][i];
		printf("%s: %d\n", ominaisuudet[i], sankarit[hahmoID].ominaisuudet[i]);
	}

	pisteet(hahmoID);

	system("cls");
	printf("Hahmosi lopulliset ominaisuudet ovat:\nVoima:%d\nTaito:%d\n\x8elykkyys:%d\nOnni:%d\n\n\nSeuraavaksi p\x84\x84set edunvalintaan.\n\n", sankarit[hahmoID].ominaisuudet[0], sankarit[hahmoID].ominaisuudet[1], sankarit[hahmoID].ominaisuudet[2], sankarit[hahmoID].ominaisuudet[3]);
	system("pause");

	edunValinta(hahmoID);

	tallennus();

	system("cls");
	return esikatselu(hahmoID);
}

void edunValinta(int hahmoID)
{
	int valitut[3] = { -1, -1, -1 };

	for (int i = 0; i < EDUT; i++)
	{
		system("cls");
		printf("Valitse %d. etu: \n", i + 1);

		for (int j = 0; j < EDUT_MAX; j++)
		{
			int onJo = 0;
			for (int k = 0; k < 3; k++)
			{
				if (valitut[k] == j) onJo = 1;
			}
			
			if(!onJo) printf("%d. %s:   %s\n", j + 1, edut[j], edutSelitykset[j]);
		}

		while (scanf_s("%d", &valitut[i]) == 0 || valitut[i] > 20)
		{
			printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
			fflush(stdin);
		}

		sankarit[hahmoID].edut[i] = --valitut[i];
	}
}

int esikatselu(int hahmoID)
{
	int valinta = 0;

	printf("Esikatselu!\n\n");

	printf("Sankari: %s\n", sankarit[hahmoID].nimi);
	printf("Rotu: %s\n", rodut[sankarit[hahmoID].rotu]);
	printf("Luokka: %s\n", luokat[sankarit[hahmoID].luokka]);
	for( int i = 0; i < OMINAISUUDET; i++)
	{
		printf("%s: %d  ", ominaisuudet[i], sankarit[hahmoID].ominaisuudet[i]);
	}
	
	printf("\nTaidot: ");
	for (int i = 0; i < TAIDOT; i++)
	{
		printf("%s", taidot[sankarit[hahmoID].luokka][i]);
		if (i != TAIDOT - 1) printf(", ");
	}

	printf("\nEdut: ");
	for (int i = 0; i < EDUT; i++)
	{
		printf("%s", edut[sankarit[hahmoID].edut[i]]);

		if (i != EDUT-1) printf(", ");
	}
		
	printf("\n\n1. Poista\n2. Takaisin selaukseen\n0. P\x84\x84valikko");

	while (scanf_s("%d", &valinta) == 0 || valinta < 0 || valinta > 3)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}

	if (valinta == 1)
	{
		system("cls");
		return poisto(hahmoID);
	}
	else
	{
		system("cls");
		return valinta;
	}

}

void rodunValinta(int hahmoID)
{
	printf("Sankari: %s", sankarit[hahmoID].nimi);

	printf("\n\nValitse rotu.\n\n");
	for (int i = 0; i < RODUT; i++)
	{
		printf("%d. %s\n", i + 1, rodut[i]);
	}
	while (scanf_s("%d", &sankarit[hahmoID].rotu) == 0 || sankarit[hahmoID].rotu < 1 || sankarit[hahmoID].rotu > RODUT)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}
	sankarit[hahmoID].rotu--;

}

void luokanValinta(int hahmoID)
{
	printf("Sankari: %s\n", sankarit[hahmoID].nimi);
	printf("Rotu: %s\n", rodut[sankarit[hahmoID].rotu]);

	printf("\nValitse luokka.\n\n");
	for (int i = 0; i < LUOKAT; i++)
	{
		printf("%d. %s\n", i + 1, luokat[i]);
	}
	while (scanf_s("%d", &sankarit[hahmoID].luokka) == 0 || sankarit[hahmoID].luokka < 1 || sankarit[hahmoID].luokka > LUOKAT)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}
	sankarit[hahmoID].luokka--;
}

void pisteet(int hahmoID)
{
	for (int j = OMINAISUUDET; j > 0; j--)
	{
		system("cls");
		int valinta = 0;
		printf("Sankari: %s\n", sankarit[hahmoID].nimi);
		printf("Rotu: %s\n", rodut[sankarit[hahmoID].rotu]);
		printf("Luokka: %s\n\n", luokat[sankarit[hahmoID].luokka]);

		printf("Hahmosi ominaisuudet ovat:\nVoima:%d\nTaito:%d\n\x8elykkyys:%d\nOnni:%d\n\nSinulla on %d pistett\x84 k\x84ytett\x84viss\x84 vapaasti valitsemiisi ominaisuuksiin.\nPisteet asetetaan yksi kerrallaan.\n\n1.Voimaa\n2.Taitoa\n3.\x8elykkyytt\x84\n4.Onnea\n\n", sankarit[hahmoID].ominaisuudet[0], sankarit[hahmoID].ominaisuudet[1], sankarit[hahmoID].ominaisuudet[2], sankarit[hahmoID].ominaisuudet[3], j);

		while (scanf_s("%d", &valinta) == 0 || valinta < 1 || valinta > 4)
		{
			printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
			fflush(stdin);
		}

		valinta--;

		sankarit[hahmoID].ominaisuudet[valinta]++;

	}
}

int selaus()
{
	int valinta = 0;
	do
	{
		printf("Hemuli-hahmonluontity\x94kalu!\nValitse hahmo\n\n", sankareita);

		for (int i = 0; i < sankareita; i++)
		{
			printf("%d: %s\n", i + 1, sankarit[i].nimi);
		}

		printf("0. P\x84\x84valikko");

		scanf_s("%d", &valinta);
		printf("\n");

	} while (valinta < 0 || valinta > sankareita);
	if (valinta == 0)
	{
		system("cls");
		return valinta;
	}
	else
	{
		system("cls");
		return esikatselu(--valinta);
	}
}

void lataus()
{
	FILE *Hahmot;
	fopen_s(&Hahmot, "hahmot.txt", "r");

	if (Hahmot != 0)
	{
		fscanf_s(Hahmot, "%d\n", &sankareita);

		sankarit = malloc(sizeof(sankari) * sankareita);

		for (int i = 0; i < sankareita; i++)
		{
			char temp[MERKIT];
			fgets(temp, MERKIT, Hahmot);
			strncpy_s(sankarit[i].nimi, strlen(temp), temp, strlen(temp) - 1);
			fscanf_s(Hahmot, "%d\n", &sankarit[i].rotu);
			fscanf_s(Hahmot, "%d\n", &sankarit[i].luokka);
			for (int j = 0; j < EDUT; j++)
			{
				fscanf_s(Hahmot, "%d\n", &sankarit[i].edut[j]);
			}
			for (int j = 0; j < OMINAISUUDET; j++)
			{
				fscanf_s(Hahmot, "%d\n", &sankarit[i].ominaisuudet[j]);
			}
		}
		fclose(Hahmot);
	}

	lataaTiedot("data\\rodut.txt", rodut, RODUT);
	lataaTiedot("data\\luokat.txt", luokat, LUOKAT);
	lataaTiedot("data\\edut.txt", edut, EDUT_MAX);
	lataaTiedot("data\\edut_selitykset.txt", edutSelitykset, EDUT_MAX);
	lataaTiedot("data\\ominaisuudet.txt", ominaisuudet, OMINAISUUDET);

	lataaTiedot("data\\taidot_soturi.txt", taidot[0], TAIDOT);
	lataaTiedot("data\\taidot_metsastaja.txt", taidot[1], TAIDOT);
	lataaTiedot("data\\taidot_velho.txt", taidot[2], TAIDOT);
	lataaTiedot("data\\taidot_varas.txt", taidot[3], TAIDOT);
	lataaTiedot("data\\taidot_pappi.txt", taidot[4], TAIDOT);

	system("cls");
}

void tallennus()
{
	FILE *Hahmot;
	fopen_s(&Hahmot, "hahmot.txt", "w");

	if (Hahmot != 0)
	{
		fprintf(Hahmot, "%d\n", sankareita);

		for (int i = 0; i < sankareita; i++)
		{
			fputs(sankarit[i].nimi, Hahmot);
			fputs("\n", Hahmot);
			fprintf(Hahmot, "%d\n", sankarit[i].rotu);
			fprintf(Hahmot, "%d\n", sankarit[i].luokka);
			for (int j = 0; j < EDUT; j++)
			{
				fprintf(Hahmot, "%d\n", sankarit[i].edut[j]);
			}
			for (int j = 0; j < OMINAISUUDET; j++)
			{
				fprintf(Hahmot, "%d\n", sankarit[i].ominaisuudet[j]);
			}
		}
		fclose(Hahmot);
	}
}

int poisto(int hahmoID)
{
	char valinta;
	printf("Hahmo %s poistetaan.\n", sankarit[hahmoID].nimi);

	do 
	{
		printf("(Y/N) > ");
		fflush(stdin);
		scanf_s("%c", &valinta, 1);
	} while (valinta != 'Y' && valinta != 'y' && valinta != 'N' && valinta != 'n');

	switch (valinta)
	{
		case 'y':
		case 'Y': 
		{
			sankari *taulukko;
			taulukko = malloc(sizeof(sankari)*sankareita - 1);

			for (int i = 0, j = 0; i < sankareita; i++)
			{
				if (i != hahmoID)
				{
					taulukko[j] = sankarit[i];
					j++;
				}
			}

			free(sankarit);
			sankarit = taulukko;
			sankareita -= 1;

			tallennus();

			break;
		}
	}

	system("cls");
	return 0;
}

void lataaTiedot(char * polku, char * taulukko[], int koko)
{
	FILE *tiedosto;
	fopen_s(&tiedosto, polku, "r");

	if (tiedosto != 0)
	{
		for (int i = 0; i < koko; i++)
		{
			char temp[MERKIT];
			fgets(temp, MERKIT, tiedosto);

			for (unsigned int i = 0; i < strlen(temp); i++)
			{
				if (temp[i] == -28) temp[i] = '\x84';
				else if (temp[i] == -10) temp[i] = '\x94';
				else if (temp[i] == -60) temp[i] = '\x8e';
				else if (temp[i] == -42) temp[i] = '\x99';
			}

			taulukko[i] = malloc(sizeof(char)*strlen(temp));

			strncpy_s(taulukko[i], strlen(temp), temp, strlen(temp) - 1);
		}

		fclose(tiedosto);
	}
}

void poistaTiedot()
{
	// Tämä funktio vapauttaa kaiken dynaamisesti varatun tilan.
	free(sankarit);

	for (int i = 0; i < RODUT; i++)
	{
		free(rodut[i]);
	}

	for (int i = 0; i < LUOKAT; i++)
	{
		free(luokat[i]);
	}

	for (int i = 0; i < EDUT_MAX; i++)
	{
		free(edut[i]);
	}

	for (int i = 0; i < EDUT_MAX; i++)
	{
		free(edutSelitykset[i]);
	}

	for (int i = 0; i < LUOKAT; i++)
	{
		for (int j = 0; j < TAIDOT; j++)
		{
			free(taidot[i][j]);
		}
	}
}