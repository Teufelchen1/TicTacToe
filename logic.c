#include "global.h"

int checkMove(char * playground, int posx, int posy)
{
	if(playground[(posy-1)*3+posx-1] == ' ') return 1;
	return 0;
}

int checkRow(char * playground, char user)
{
	int p;
	char won = 0;

	// code to check a row
	for(p = 0; p < 3 && won == 0; p++){
		if((playground[p*3+0] == user) && (playground[p*3+1] == user) && (playground[p*3+2] == user)) won += 1;
	}
	for(p = 0; p < 3 && won == 0; p++){
		if((playground[3*0+p] == user) && (playground[3*1+p] == user) && (playground[3*2+p] == user)) won += 1;
	}
	if((playground[3*0+0] == user) && (playground[3*1+1] == user) && (playground[3*2+2] == user)) won += 1;
	if((playground[3*0+2] == user) && (playground[3*1+1] == user) && (playground[3*2+0] == user)) won += 1;
	return won;
}

char checkField(char * playground)
{
	int won = 0;

	won = checkRow(playground,'o');
	if(won > 0) return 'o';
	won = checkRow(playground,'x');
	if(won > 0) return 'x';

	return 0;
}

int centerFree(char * playground)
{
	if(playground[4] == ' ') return 1;
	else return 0;
}

int selectCorner(char * playground)
{
	int c = 0;
	int k = rand() & 3;
	do{
		if(k == 0) c = 0;
		if(k == 1) c = 2;
		if(k == 2) c = 6;
		if(k == 3) c = 8;
		k++;
	} while(playground[c] != ' ' && k < 5);
	if(k > 4)
		return -1;
	return c;
}

int selectMiddle(char * playground)
{
	int c = 0;
	int k = rand() & 3;
	do{
		if(k == 0) c = 1;
		if(k == 1) c = 3;
		if(k == 2) c = 5;
		if(k == 3) c = 7;
		k++;
	} while(playground[c] != ' ' && k < 5);
	if(k > 4)
		return -1;
	return c;
}

int findBlock(char * playground)
{
	int count = 0;
	int p;
	for(p = 0; p < 3; p++){
		if(playground[p*3+0] == 'x') 
			count += 1;
		if(playground[p*3+1] == 'x') 
			count += 1;
		if(playground[p*3+2] == 'x') 
			count += 1;
		if(count == 2){
			if(playground[p*3+0] == ' ') 
				return p*3+0;
			if(playground[p*3+1] == ' ')
				return p*3+1;
			if(playground[p*3+2] == ' ')
				return p*3+2;
		}
		count = 0;
	}
	for(p = 0; p < 3; p++){
		if(playground[3*0+p] == 'x')
			count += 1; 
		if(playground[3*1+p] == 'x')
			count += 1;
		if(playground[3*2+p] == 'x') 
			count += 1;
		if(count == 2){
			if(playground[3*0+p] == ' ')
				return 3*0+p;
			if(playground[3*1+p] == ' ')
				return 3*1+p;
			if(playground[3*2+p] == ' ')
				return 3*2+p;
		}
		count = 0;
	}
	if(playground[3*0+0] == 'x')
		count += 1;
	if(playground[3*1+1] == 'x')
	 	count += 1;
	if(playground[3*2+2] == 'x')
	 	count += 1;
	if(count == 2){
		if(playground[3*0+0] == ' ')
			return 3*0+0;
		if(playground[3*1+1] == ' ')
		 	return 3*1+1;
		if(playground[3*2+2] == ' ')
		 	return 3*2+2;
	}
	count = 0;
	if(playground[3*0+2] == 'x')
		count += 1;
	if(playground[3*1+1] == 'x')
	 	count += 1;
	if(playground[3*2+0] == 'x')
	 	count += 1;
	if(count == 2){
		if(playground[3*0+2] == ' ')
			return 3*0+2;
		if(playground[3*1+1] == ' ')
		 	return 3*1+1;
		if(playground[3*2+0] == ' ')
		 	return 3*2+0;
	}
	return -1;
}

int findWin(char * playground)
{
	int count = 0;
	int p;
	for(p = 0; p < 3; p++){
		if(playground[p*3+0] == 'o') 
			count += 1;
		if(playground[p*3+1] == 'o') 
			count += 1;
		if(playground[p*3+2] == 'o') 
			count += 1;
		if(count == 2){
			if(playground[p*3+0] == ' ') 
				return p*3+0;
			if(playground[p*3+1] == ' ')
				return p*3+1;
			if(playground[p*3+2] == ' ')
				return p*3+2;
		}
		count = 0;
	}
	for(p = 0; p < 3; p++){
		if(playground[3*0+p] == 'o')
			count += 1; 
		if(playground[3*1+p] == 'o')
			count += 1;
		if(playground[3*2+p] == 'o') 
			count += 1;
		if(count == 2){
			if(playground[3*0+p] == ' ')
				return 3*0+p;
			if(playground[3*1+p] == ' ')
				return 3*1+p;
			if(playground[3*2+p] == ' ')
				return 3*2+p;
		}
		count = 0;
	}
	printf("check Diognal\n");
	if(playground[3*0+0] == 'o')
		count += 1;
	if(playground[3*1+1] == 'o')
	 	count += 1;
	if(playground[3*2+2] == 'o')
	 	count += 1;
	if(count == 2){
		if(playground[3*0+0] == ' ')
			return 3*0+0;
		if(playground[3*1+1] == ' ')
		 	return 3*1+1;
		if(playground[3*2+2] == ' ')
		 	return 3*2+2;
	}
	printf("check other dia\n");
	count = 0;
	if(playground[3*0+2] == 'o')
		count += 1;
	if(playground[3*1+1] == 'o')
	 	count += 1;
	if(playground[3*2+0] == 'o')
	 	count += 1;
	if(count == 2){
		if(playground[3*0+2] == ' ')
			return 3*0+2;
		if(playground[3*1+1] == ' ')
		 	return 3*1+1;
		if(playground[3*2+0] == ' ')
		 	return 3*2+0;
	}
	printf("whaaat\n");
	return -1;
}

int findDoubleCorner(char * playground)
{
	if(((playground[0] == 'x') && (playground[8] == 'x')) || ((playground[2] == 'x') && (playground[6] == 'x')))
		return 1;
	return 0;
}

int selectFree(char * playground)
{
	int i;
	for(i = 0; i < 9; i++)
	{
		if(playground[i] == ' ')
			return i;
	}
	return -1;
}

int player(char * playground, int rnum)
{
	char c;
	if(centerFree(playground)){
		return 4;
	}
	c = findWin(playground);
	if(c < 0){
		c = findBlock(playground);
		if(c < 0){
			if(rnum < 4 && !findDoubleCorner(playground)){
				c = selectCorner(playground);
			}
			else{
				c = selectMiddle(playground);
			}
			if(c < 0){
				c = selectCorner(playground);
				if(c < 0){
					c = selectFree(playground);
				}
			}
		}
	}
	return c;
}