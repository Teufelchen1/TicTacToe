#include <stdio.h>
#include "helper.c"
#include "logic.c"

int main()
{
	char c = 0;

	char playground[9];
	delField(playground);

	c = gameLoop(playground);
	system("cls");
	drawField(playground,2,2);
	if(c != 0) printf("Spieler %c hat gewonnen!\n", c);
	else printf("Spielende! Unentschieden!\n");
	return 0;
}