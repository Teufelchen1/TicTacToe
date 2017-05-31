#include <string.h>
#include <stdio.h>


void drawField(char * playground, int posx, int posy);
char handleUser(void);

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
#endif
