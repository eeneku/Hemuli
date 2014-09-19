#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_HEROES 5

struct hero
{
	char name[25];
	int strength;
	int dexterity;
	int intelligence;
};

int main()
{
	srand(time(NULL));

	struct hero heroes[NUM_OF_HEROES];

	for (int i = 0; i < NUM_OF_HEROES; i++)
	{
		sprintf_s(heroes[i].name, 8, "%d. hero", i + 1);

		heroes[i].strength = rand() % 10 + 1;
		heroes[i].dexterity = rand() % 10 + 1;
		heroes[i].intelligence = rand() % 10 + 1;

		printf("%s\nStrength: %d\nDexterity: %d\nIntelligence: %d\n\n", heroes[i].name, heroes[i].strength, heroes[i].dexterity, heroes[i].intelligence);
	}

	return 0;
}