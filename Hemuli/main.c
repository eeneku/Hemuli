#include <stdio.h>
#include <stdlib.h>

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
int pisteet(hahmoID);

char rodut[RODUT][MERKIT] = { "Ihminen", "Haltia", "K\x84\x84pi\x94", "Puoli\x94rkki", "Hobitti" };
char luokat[LUOKAT][MERKIT] = { "Soturi", "Mets\x84st\x84j\x84", "Velho", "Varas", "Pappi" };
char edut[EDUT_MAX][MERKIT] = { "Haukankatse", "Nopea reaktiokyky", "Akrobatia", "Kaappi", "Lemmikki", "Veriuhraus", "Hannu Hanhi", "Manan lapsi", "Kitupiikki", "Iso P\x84\x84", "Lukutoukka", "N\x84pp\x84r\x84", "Johtaja", "Pyh\x84", "K\x84rsim\x84t\x94n", "Kirottu", "Kultakutri", "Mielenhallinta", "Karaistu", "Hipsteri" };
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
		printf("Virheellinen sy�te! Yrit� uudelleen: > ");
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
	while (scanf_s("%d", &temp.rotu) == 0 || temp.rotu < 1 || temp.rotu > RODUT)
	{
		printf("Virheellinen sy�te! Yrit� uudelleen: > ");
		fflush(stdin);
	}
	temp.rotu--;

	printf("\n\nValitse luokka.\n\n");
	for (int i = 0; i < LUOKAT; i++)
	{
		printf("%d. %s\n", i + 1, luokat[i]);
	}
	while (scanf_s("%d", &temp.luokka) == 0 || temp.luokka < 1 || temp.luokka > LUOKAT)
	{
		printf("Virheellinen sy�te! Yrit� uudelleen: > ");
		fflush(stdin);
	}
	temp.luokka--;

	printf("\n\nOminaisuude:\n\n");
	for (int i = 0; i < OMINAISUUDET; i++)
	{
		temp.ominaisuudet[i] = rotuArvot[temp.rotu][i];
		printf("%s: %d\n", ominaisuudet[i], temp.ominaisuudet[i]);
	}
	
	printf("\n\nULIULI! Sait taidot: \n\n");
	for (int i = 0; i < TAIDOT; i++)
	{
		printf("%s\n", taidot[temp.luokka][i]);
	}

	// EDUT 
	while (scanf_s("%d", &temp.edut[0]) == 0)
	{
		printf("Virheellinen sy�te! Yrit� uudelleen: > ");
		fflush(stdin);
	}

	system("cls");
	return esikatselu(0);
}

int esikatselu(int hahmoID)
{
	int valinta = 0;

	printf("Esikatselu!\n\n1. Muokkaa\n2. Takaisin selaukseen\n0. P\x84\x84valikko");
	printf("\n");

	while (scanf_s("%d", &valinta) == 0 || valinta < 0 || valinta > 2)
	{
		printf("Virheellinen sy�te! Yrit� uudelleen: > ");
		fflush(stdin);
	}

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

int pisteet(int hahmoID)
{
	for (int i = 4; i > 0; i--)
	{
		printf("Hahmosi ominaisuudet ovat \nSinulla on %d pistett� k�ytett�viss� vapaasti valitsemiisi ominaisuuksiin.\n\n1.Voima\n2.Taito\n3.�lykkyys\n4.Onni", i);
		scanf_s("%d", rotuArvot[]++);
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