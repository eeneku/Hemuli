#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct sankari
{
	char nimi[25];
	int rotu;
	int luokka;
	int taidot[5];
	int edut[3];
	int voima;
	int taito;
	int viisaus;
	int onni;
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

char rodut[5][25] = { "ihminen", "haltia", "kääpiö", "hobitti", "örkki" };
char taidot[5][25] = { "vimmaisku", "tulipallo", "kadotus", "jääisku", "korpo" };
char edut[5][25] = { "iso pää", "pienet lihakset", "ei jalkoja", "sormeton", "musta kieli" };

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

	printf("\n\nValitse VOIMA.");
	scanf_s("%d", &temp.voima);

	printf("\n\nValitse TAITO.");
	scanf_s("%d", &temp.taito);

	printf("\n\nValitse VIISAUS.");
	scanf_s("%d", &temp.viisaus);

	printf("\n\nValitse ONNI.");
	scanf_s("%d", &temp.onni);

	for (int i = 0; i < 5; i++)
	{
		printf("\n\nValitse taidot.\n\n1.sdfsfsdf\n\n2.sdfsdfsdf\n\n3.sdfasfergds");
		scanf_s("%d", &temp.taidot[i]);
	}

	for (int i = 0; i < 3; i++)
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
