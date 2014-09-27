#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct hero
{
	char name[25];
	int strength;
	int dexterity;
	int intelligence;
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

	printf("Hemuli-hahmonluontity\x94kalu!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	scanf_s("%d", &valinta);
	printf("\n");

	return valinta;
}

int luonti()
{
	printf("Hahmonluonti\n\nM: Muokkaus\n\n");

	return esikatselu(0);
}

int esikatselu(int hahmoID)
{
	printf("Hahmon esikatselu.\n\n");

	return 0;
}

int hahmonMuokkaus(int hahmoID)
{
	printf("Hahmonmuokkaus.\n\n");

}

int tiedonMuokkaus(int hahmoID)
{
	printf("Muuta hahmon tietoja.\n\n");
}

int selaus()
{
	printf("Selaa luotuja hahmoja.\n\n");

	return 0;
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
