#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RODUT 5
#define TAIDOT 5
#define EDUT 3
#define OMINAISUUDET 4
#define MERKIT 25

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

const char * annaTaito(int taitoID);

char rodut[RODUT][25] = { "ihminen", "haltia", "k\x84\x84pi\x94", "hobitti", "\x94rkki" };
char taidot[TAIDOT][25] = { "vimmaisku", "tulipallo", "kadotus", "j\x84\x84isku", "korpo" };
char edut[5][25] = { "iso p\x84\x84", "pienet lihakset", "ei jalkoja", "sormeton", "musta kieli" };
char ominaisuudet[OMINAISUUDET][25] = { "voima", "taito", "\x84lykkyys", "onni" };
int rotuArvot[RODUT][4];


int main()
{
	printf("%s\n", rodut[3]);
	printf("%s\n", taidot[4]);
	printf("%s\n", edut[3]);

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
		system("cls");
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

	printf("Hemuli-hahmonluontity\x94kalu!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	scanf_s("%d", &valinta);
	printf("\n");

	return valinta;
}

int luonti()
{
	struct sankari temp;

	printf("Hahmonluonti!\n\nSy\x94t\x84 hahmon nimi. >");
	
	printf("\n\nValitse rotu.\n\n1.Ihminen\n2.Haltia\n3.Peikko\n4.Joulupukki");
	scanf_s("%d", &temp.rotu);

	printf("\n\nValitse luokka.\n\n1.Soturi\n\n2.Velho\n\n3.Varas");
	scanf_s("%d", &temp.luokka);

	for (int i = 0; i < OMINAISUUDET; i++)
	{
		printf("\n\nValitse %s.", ominaisuudet[i]);
		scanf_s("%d", &temp.ominaisuudet[i]);
	}
	

	for (int i = 0; i < TAIDOT; i++)
	{
		printf("\n\nValitse taidot.\n\n1.sdfsfsdf\n\n2.sdfsdfsdf\n\n3.sdfasfergds");
		scanf_s("%d", &temp.taidot[i]);
	}

	for (int i = 0; i < EDUT; i++)
	{
		printf("\n\nValitse etu.\n\n1.jooo\n\n2.jaaa\n\n3.jeee");
		scanf_s("%d", &temp.edut[i]);
	}

	return esikatselu(0);
}

int esikatselu(int hahmoID)
{
	int valinta = 0;
	do
	{
		printf("Esikatselu!\n\n1. Muokkaa\n2. Takaisin selaukseen\n0. P\x84\x84valikko");
		scanf_s("%d", &valinta);
		printf("\n");

	} while (valinta < 0 || valinta > 2);
	if (valinta == 1)
	{
		return hahmonMuokkaus(hahmoID);
	}
	else
	{
		return valinta;
	}
}

int hahmonMuokkaus(int hahmoID)
{
	printf("Hahmonmuokkaus.\n\n");
	return 0;
}

int tiedonMuokkaus(int hahmoID)
{
	printf("Muuta hahmon tietoja.\n\n");
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
		return valinta;
	}
	else
	{
		return esikatselu(valinta);
	}
}

int lataus()
{

}

int tallennus()
{

}

int poisto(int hahmoID)
{
	printf("Oletko varma etta haluat poistaa hahmon? Y/N >");
	scanf_s("%d", &poisto);
}

const char * annaTaito(int taitoID)
{
	const char * taito = "Vimmajoo!";

	return taito;
}
