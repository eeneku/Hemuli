#include <stdio.h>
#include <stdlib.h>

#define RODUT 5
#define LUOKAT 5
#define TAIDOT 5
#define EDUT 3
#define OMINAISUUDET 4
#define MERKIT 25
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
int esikatselu(hahmoID);
int hahmonMuokkaus(hahmoID);
int tiedonMuokkaus(hahmoID);
int selaus();
void lataus();
void tallennus();
int poisto(hahmoID);
void pisteet(hahmoID);

char rodut[RODUT][MERKIT] = { "Ihminen", "Haltia", "K\x84\x84pi\x94", "Puoli\x94rkki", "Hobitti" };

char luokat[LUOKAT][MERKIT] = { "Soturi", "Mets\x84st\x84j\x84", "Velho", "Varas", "Pappi" };

char edut[EDUT_MAX][MERKIT] = { "Haukankatse", "Nopea reaktiokyky", "Akrobatia", "Kaappi", "Lemmikki", "Veriuhraus", "Hannu Hanhi", "Manan lapsi",
"Kitupiikki", "Iso P\x84\x84", "Lukutoukka", "N\x84pp\x84r\x84", "Johtaja", "Pyh\x84", "K\x84rsim\x84t\x94n", "Kirottu", "Kultakutri", "Mielenhallinta", "Karaistu", "Hipsteri" };

char edutSelitykset[EDUT_MAX][MERKIT * 4] = { "+10 % kriittisen osuman todenn\x84k\x94isyys.",
"+15 % v\x84ist\x94mahdollisuus, nakkijonossa +100 %.", "50 % mahdollisuus vastaiskuun v\x84ist\x94n j\x84lkeen.",
"Valtavat muskelit! Kaksinkertainen kriittisen osuman vahinko.", "Voi auttaa satunnaisesti taistelussa, muista siivota j\x84t\x94kset.",
"Voi vaihtaa elinvoimaansa v\x84liaikaiseen voimanlis\x84ykseen.", "Onnen vaikutus tehostuu, ei voi k\x84ytt\x84\x84 housuja.",
"Taikojen heitto 20 % helpomaa.", "Varusteet ja esineet 10 % halvemmalla.", "+10 % taikuuden teho, -10 % elinvoimaa.",
"Oppii uusia taitoja nopeammin, -5 onnea tavernoissa.", "Osaa korjata ja parannella omia varusteitaan.",
"L\x84hell\x84 oleville liittolaisille +5 % kaikkiin ominaisuuksiin.", "Tuplavahinko ep\x84kuolleita vastaan.", "Iskee aina ensimm\x84isen\x84, -15 % kaikkiin ominaisuuksiin.",
"Rumat kasvonpiirteet, 0,5 % mahdollisuus s\x84ik\x84ytt\x84\x84 vastustaja.", "Elovena-malli, 0,5 % mahdollisuus hurmata vihollinen.",
"Voi ohjailla v\x84h\x84-\x84lyisi\x84 otuksia ja juoppoja.", "+10 % elinvoimaa, muista k\x84ytt\x84\x84 hilseshampoota.", "Ei t\x84st\x84 oikeasti mit\x84\x84n hy\x94ty\x84 ole." };

char ominaisuudet[OMINAISUUDET][MERKIT] = { "Voima", "Taito", "\x8elykkyys", "Onni" };

char taidot[LUOKAT][TAIDOT][MERKIT] = { 
		{ "kilpi-isku", "sotahuuto", "rynn\x84kk\x94", "vimmaly\x94nti", "heitto" }, 
		{ "ansa", "myrkkynuoli", "j\x84ljitys", "v\x84ijytys", "nuolisade" }, 
		{ "tulipallo", "muodonmuutos", "levitointi", "j\x84\x84kilpi", "paineaalto" }, 
		{ "heittot\x84hdet", "pikajuoksu", "savupommi", "aseistariisunta", "tiirikointi"}, 
		{ "parannus", "syntien poltto", "sauvaisku", "pyh\x84 kilpi", "sokaisu" } };

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

	free(sankarit);

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
	printf("\nHemuli-hahmonluontity\x94kalu!\n\n1. Luo hahmo\n2. Selaa hahmoja\n3. Lopeta\n");
	
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

	printf("\n\nValitse luokka.\n\n");
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

	printf("\n\nOminaisuudet:\n\n");
	for (int i = 0; i < OMINAISUUDET; i++)
	{
		sankarit[hahmoID].ominaisuudet[i] = rotuArvot[sankarit[hahmoID].rotu][i];
		printf("%s: %d\n", ominaisuudet[i], sankarit[hahmoID].ominaisuudet[i]);

	}

	pisteet(hahmoID);

	printf("Hahmosi lopulliset ominaisuudet ovat:\nVoima:%d\nTaito:%d\n\x8elykkyys:%d\nOnni:%d\n\n", sankarit[hahmoID].ominaisuudet[0], sankarit[hahmoID].ominaisuudet[1], sankarit[hahmoID].ominaisuudet[2], sankarit[hahmoID].ominaisuudet[3]);
	printf("\n\nULIULI! Sait taidot: \n\n");
	for (int i = 0; i < TAIDOT; i++)
	{
		printf("%s\n", taidot[sankarit[hahmoID].luokka][i]);
	}

	// EDUT 
	for (int i = 0; i < EDUT; i++)
	{
		sankarit[hahmoID].edut[i] = 0;
	}
	while (scanf_s("%d", &sankarit[hahmoID].edut[0]) == 0)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}

	tallennus();

	system("cls");
	return esikatselu(hahmoID);
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
		
	printf("\n\n1. Muokkaa\n2. Takaisin selaukseen\n3. Poista\n0. P\x84\x84valikko");

	while (scanf_s("%d", &valinta) == 0 || valinta < 0 || valinta > 3)
	{
		printf("Virheellinen sy\x94te! Yrit\x84 uudelleen: > ");
		fflush(stdin);
	}

	if (valinta == 1)
	{
		system("cls");
		return hahmonMuokkaus(hahmoID);
	}
	else if (valinta == 3)
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

void pisteet(int hahmoID)
{
	for (int j = OMINAISUUDET; j > 0; j--)
	{
		system("cls");
		int valinta = 0;
		printf("Hahmosi ominaisuudet ovat:\nVoima:%d\nTaito:%d\n\x8elykkyys:%d\nOnni:%d\n\nSinulla on %d pistett\x8e k\x8eytett\x8eviss\x8e vapaasti valitsemiisi ominaisuuksiin.\n\n1.Voima\n2.Taito\n3.\x8elykkyys\n4.Onni\n\n", sankarit[hahmoID].ominaisuudet[0], sankarit[hahmoID].ominaisuudet[1], sankarit[hahmoID].ominaisuudet[2], sankarit[hahmoID].ominaisuudet[3], j);
		scanf_s("%d", &valinta);

		valinta--;
		sankarit[hahmoID].ominaisuudet[valinta]++;
	}

	system("cls");
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
		printf("Hemuli-hahmonluontity\x94kalu!\nValitse hahmo\n\n", sankareita);

		for (int i = 0; i < sankareita; i++)
		{
			printf("%d: %s", i + 1, sankarit[i].nimi);
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
			fgets(sankarit[i].nimi, MERKIT, Hahmot);
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

	do {
		printf("(Y/N) > ");
		fflush(stdin);
		scanf_s("%c", &valinta, 1);
	} while (valinta != 'Y' && valinta != 'y' && valinta != 'N' && valinta != 'n');

	switch (valinta)
	{
	case 'y':
	case 'Y': {
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
	};

	system("cls");
	return 0;
}