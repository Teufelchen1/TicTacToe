#include <string.h>
#include <stdio.h>

void delField(char * field);
void drawField(char * playground, int posx, int posy);
char gameloop(char * playground);
unsigned char handleUser(void);

int checkMove(char * playground, int posx, int posy);
char checkField(char * playground);
int player(char * playground, int rnum);


#ifdef linux
#include <unistd.h>
#include <termios.h>
extern int rand(void);
char _getch(void);
void system(const char * str);
#endif

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#endif
