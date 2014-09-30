#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define RODUT 5
#define LUOKAT 5
#define TAIDOT 5
#define EDUT 3
#define OMINAISUUDET 4
#define MERKIT 25
#define EDUT_MAX 20

struct sankari
{
	char nimi[MERKIT];
	int rotu;
	int luokka;
	int taidot[TAIDOT];
	int edut[EDUT];
	int ominaisuudet[OMINAISUUDET];
};

void introkuva();
int paavalikko();
int luonti();
int esikatselu(hahmoID);
int hahmonMuokkaus(hahmoID);
int tiedonMuokkaus(hahmoID);
int selaus();
int lataus();
int tallennus();
int poisto(hahmoID);

char rodut[RODUT][MERKIT] = { "ihminen", "haltia", "k\x84\x84pi\x94", "puoli\x94rkki", "hobitti" };
char luokat[LUOKAT][MERKIT] = { "soturi", "mets\x84st\x84j\x84", "velho", "varas", "pappi" };
char edut[EDUT_MAX][MERKIT] = { "iso p\x84\x84", "pienet lihakset", "ei jalkoja", "sormeton", "musta kieli" };
char ominaisuudet[OMINAISUUDET][MERKIT] = { "voima", "taito", "\x84lykkyys", "onni" };
char taidot[LUOKAT][TAIDOT][MERKIT] = { 
		{ "kilpi-isku", "sotahuuto", "rynn\x84kk\x94", "vimmaly\x94nti", " " }, 
		{ "ansa", "myrkkynuoli", "j\x84ljitys", "v\x84ijytys", "nuolisade" }, 
		{ "tulipallo", "muodonmuutos", "levitointi", "j\x84\x84kilpi", "paineaalto" }, 
		{ "heittot\x84hdet", "pikajuoksu", "savupommi", "aseistariisunta", " "}, 
		{ "parannus", "syntien poltto", "sauvaisku", "pyh\x84 kilpi", "sokaisu" } };
int rotuArvot[RODUT][OMINAISUUDET] = {
		{ 5, 5, 5, 5 }, 
		{ 4, 6, 7 ,3 }, 
		{ 7, 4, 4, 5},
		{ 8, 5, 3, 4 }, 
		{ 3, 6, 5, 6 }};

int main()
{
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

	printf("\nHemuli-hahmonluontity\x94kalu!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	
	while (scanf_s("%d", &valinta) == 0)
	{
		printf("\nMerkit vittuun! Kokeile uusiks...\n");
		fflush(stdin);
	}

	printf("\n");

	system("cls");
	return valinta;
}

int luonti()
{
	struct sankari temp;

	printf("Hahmonluonti!\n\nSy\x94t\x84 hahmon nimi. >");
	
	printf("\n\nValitse rotu.\n\n");
	for (int i = 0; i < RODUT; i++)
	{
		printf("%d. %s\n", i + 1, rodut[i]);
	}
	scanf_s("%d", &temp.rotu);
	temp.rotu--;

	printf("\n\nValitse luokka.\n\n");
	for (int i = 0; i < LUOKAT; i++)
	{
		printf("%d. %s\n", i + 1, luokat[i]);
	}
	scanf_s("%d", &temp.luokka);
	temp.luokka--;

	for (int i = 0; i < OMINAISUUDET; i++)
	{
		temp.ominaisuudet[i] = rotuArvot[temp.rotu][i];
		printf("%s: %d\n", ominaisuudet[i], temp.ominaisuudet[i]);
	}
	
	printf("\n\nULIULI! Sait taidot: \n\n");
	for (int i = 0; i < TAIDOT; i++)
	{
		printf("%d. %s\n", i + 1, taidot[temp.luokka][i]);
	}

	for (int i = 0; i < EDUT; i++)
	{
		printf("\n\nValitse etu.\n\n1.jooo\n\n2.jaaa\n\n3.jeee");
		scanf_s("%d", &temp.edut[i]);
	}

	system("cls");
	return esikatselu(0);
}

int esikatselu(int hahmoID)
{
	int valinta = 0;

	do
	{
		printf("Esikatselu!\n\n1. Muokkaa\n2. Takaisin selaukseen\n0. P\x84\x84valikko");
		printf("\n");

	} while (scanf_s("%d", &valinta) == -1 || valinta < 0 || valinta > 2);
	if (valinta == 1)
	{
		system("cls");
		return hahmonMuokkaus(hahmoID);
	}
	else
	{
		system("cls");
		return valinta;
	}

}

int hahmonMuokkaus(int hahmoID)
{
	printf("Hahmonmuokkaus.\n\n");

	system("cls");
	return 0;
}

int tiedonMuokkaus(int hahmoID)
{
	printf("Muuta hahmon tietoja.\n\n");

	system("cls");
	return 0;
}

int selaus()
{
	int valinta = 0;
	do
	{
		printf("Hemuli-hahmonluontity\x94kalu!\n\n1.- 100. Valitse hahmo\n0. P\x84\x84valikko");
		scanf_s("%d", &valinta);
		printf("\n");

	} while (valinta < 0 || valinta > 100);
	if (valinta == 0)
	{
		system("cls");
		return valinta;
	}
	else
	{
		system("cls");
		return esikatselu(valinta);
	}
}

int lataus()
{
	printf("Lataaaaaaa... \n\n");

	system("cls");
	return 0;
}

int tallennus()
{
	printf("Tallentaaaaaaa... \n\n");

	system("cls");
	return 0;
}

int poisto(int hahmoID)
{
	printf("Oletko varma etta haluat poistaa hahmon? Y/N >");

	system("cls");
	return 0;
}