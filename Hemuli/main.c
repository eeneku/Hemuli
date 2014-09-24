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

		}
		case 2:					//Selaus
		{

		}
		case 3: break;			// Lopetus
		}
	} while (valinta != 3);		// Ohjelman lopetus

	return 0;
}

void introkuva()
{

}

int paavalikko()
{
	int valinta = 0;
	printf("Hemuli-hahmonluontityökalu!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	scanf_s("%d", &valinta);
	return valinta;
}

int luonti()
{
	printf("Hahmonluonti\n\nM: Muokkaus");

	return esikatselu(0);
}

int esikatselu(int hahmoID)
{
	printf("Hahmon esikatselu.");

}

int hahmonMuokkaus(int hahmoID)
{
	printf("Hahmonmuokkaus");

}

int tiedonMuokkaus(int hahmoID)
{
	printf("Muuta hahmon tietoja.");
}

int selaus()
{
	printf("Selaa luotuja hahmoja.");
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
