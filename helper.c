#include "global.h"

int toggle(int user)
{
	if(user == 'x') return 'o';
	else return 'x';
}

void delField(char * field)
{
	//field = { 0 };
	memset(field,' ',9);
}

void drawField(char * playground, int posx, int posy)
{
	int i,k,p;
	char field[154];
	memset(field,' ', 153);
	field[153] = 0;

	for(i = 1; i <= 9; i++){
		field[(i*17)-1] = '\n'; // minus one 'cause we start at index 0, not 1;
	}

	k = 17*2;
	for(i = 0; i < 7; i++){
		for(p = 0; p < 16; p++){
			if((p+1) % 4 == 0 && i % 2 == 0) field[k+i*17+p] = '+';
			if((p+1) > 4 && (p+1) % 4 != 0 && i % 2 == 0) field[k+i*17+p] = '-';
			if(i == 1 && (p+1) % 4 == 0) field[k+i*17+p] = '|';
			if(i == 3 && (p+1) % 4 == 0) field[k+i*17+p] = '|';
			if(i == 5 && (p+1) % 4 == 0) field[k+i*17+p] = '|';
		} 
	}

	field[1+4*posx] = '|';
	field[17+1+4*posx] = 'V';
	field[(1+2*posy)*17] = '-';
	field[(1+2*posy)*17+1] = '-';
	field[(1+2*posy)*17+2] = '>';

	for(i = 3; i < 9; i += 2){
		for(p = 0; p < 16; p ++){
			if(p == 5)field[i*17+p] = playground[(((i-1)/2)-1)*3+0];
			if(p == 9)field[i*17+p] = playground[(((i-1)/2)-1)*3+1];
			if(p == 13)field[i*17+p] = playground[(((i-1)/2)-1)*3+2];
		}
	}
	field[153] = '\0' ;
	printf("%s\n", field);
}

#ifdef _WIN32
unsigned char handleUser()
{
	unsigned char c;
	do{
		c = _getch();
		if(c == 224){
			c = _getch()
			return c;
		} 
		else if(c == 13){
			return c;
		}
		
	} while(c != 'e');
	return c;
}
#endif

#ifdef linux
unsigned char handleUser()
{
	unsigned char c;
	do{
		c = _getch();
		if(c == 27){
			c = _getch();
			if(c == 91){
				c = _getch();
				return c;
			} 
		} 
		else if(c == 10){
			return c;
		}
		
	} while(c != 'e');
	return c;
}

char _getch()
{
	static struct termios oldt, newt;

    /*tcgetattr gets the parameters of the current terminal
    STDIN_FILENO will tell tcgetattr that it should write the settings
    of stdin to oldt*/
    tcgetattr( STDIN_FILENO, &oldt);
    
    /*now the settings will be copied*/
    newt = oldt;

    /*ICANON normally takes care that one line at a time will be processed
    that means it will return if it sees a "\n" or an EOF or an EOL*/
    newt.c_lflag &= ~(ICANON | ECHO);          

    /*Those new settings will be set to STDIN
    TCSANOW tells tcsetattr to change attributes immediately. */
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);

	char c = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
	return c;
}

void system(const char * str)
{
	if(strcmp("cls",str) == 0){
		printf("\033[H\033[J");
	}
}
#endif

char gameLoop(char * playground)
{
	char job;
	int gamecount = 0;
	int posx = 2;
	int posy = 2;
	char user = 'x';

	do{
		system("cls");
		drawField(playground,posx,posy);
		printf("Spieler ist am Zug\n");
		job = handleUser();
		switch(job){
			case 67:
				if(posx < 3) posx++;
				break;
			case 68:
				if(posx > 1) posx--;
				break;
			case 65:
				if(posy > 1) posy--;
				break;
			case 66:
				if(posy < 3) posy++;
				break;
			case 10:
				if(checkMove(playground,posx,posy) == 1) {
					playground[(posy-1)*3+posx-1] = user;
					gamecount++;
					if(checkField(playground) != 0)
						return checkField(playground);
					if(gamecount < 8) {
						playground[player(playground,gamecount)] = 'o';
						gamecount++;
						if(checkField(playground) != 0)
							return checkField(playground);
					}
				}
		}

	} while(job != 'e' && gamecount < 9);
	return '\0';
}