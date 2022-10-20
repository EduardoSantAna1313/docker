/*
https://en.wikipedia.org/wiki/Knight%27s_tour

Compile:
gcc knights-tour.c -o knights-tour
Digit the initial position between {0 0} and {7 7}
*/
#include <stdio.h>

void initBoard(int *board){
	int i = 0, j = 0;
	for(i = 0; i < 8 ; i ++){
		for(j = 0; j < 8; j++){
			board[i*8 + j] = 0;
		}
	}	

}

void printBoard(int round, int board[8][8]){
	system("clear");
	printf("*****Round %i*****\n\n", round);
	int i = 0, j = 0;
	for(i = 0; i < 8 ; i ++){
		for(j = 0; j < 8; j++){
			printf("%i\t", board[i][j]);
		}
		printf("\n");
	}
}

int minor(int vector[8])
{
	int i;
	int min = 7;
	int index = 0;	
	for(i = 0; i < 8 ; i++)
	{
		if(vector[i] < min && vector[i] != 0)
		{
			min = vector[i];
			index = i;
		}
	}
	return index;
}

void plays(int x, int y, int board[8][8], int *vet)
{
	int vector[8] = { 0, 0, 0, 0, 0, 0, 0, 0};
	int qnt = 0;
	if(((x-1 > 0) || (y-2 > 0) || (x-1 < 8) || (y-2 < 8)))
	{
		if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
			x = x - 1;
			y = y - 2;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x + 1;
			y = y +	2;
			vector[0] = qnt;
		}
		if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
			x = x + 1;
			y = y - 2;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x - 1;
			y = y +	2;
			vector[1] = qnt;
		}
		if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
			x = x + 2;
			y = y - 1;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x - 2;
			y = y +	1;
			vector[2] = qnt;
		}
		if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
			x = x + 2;
			y = y + 1;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x - 2;
			y = y - 1;
			vector[3] = qnt;
		}
		if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
			x = x + 1;
			y = y + 2;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x - 1;
			y = y -	2;
			vector[4] = qnt;
		}
		if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
			x = x - 1;
			y = y + 2;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x + 1;
			y = y -	2;
			vector[5] = qnt;
		}
		if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
			x = x - 2;
			y = y + 1;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x + 2;
			y = y - 1;
			vector[6] = qnt;
		}
		if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
			x = x - 2;
			y = y - 1;
			qnt = 0;
			if(board[x-1][y-2] == 0 && (x-1 >= 0) && (y-2 >= 0)){
				qnt++;
			}
			if(board[x+1][y-2] == 0 && (x+1 <= 7) && (y -2 >= 0)){
				qnt++;
			}
			if(board[x+2][y-1] == 0 && (x+2 <= 7) && (y -1 >= 0)){
				qnt++;
			}
			if(board[x+2][y+1] == 0 && (x+2 <= 7) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x+1][y+2] == 0 && (x+1 <= 7) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-1][y+2] == 0 && (x-1 >= 0) && (y+2 <= 7)){
				qnt++;
			}
			if(board[x-2][y+1] == 0 && (x-2>= 0) && (y+1 <= 7)){
				qnt++;
			}
			if(board[x-2][y-1] == 0 && (x-2 >= 0) && (y-1 >= 0)){
				qnt++;
			}
			x = x + 2;
			y = y +	1;
			vector[7] = qnt;
		}
	}

	int i = 0;
	for(i = 0; i < 8; i++){
		*vet = vector[i];
		vet++;
	}
}

void changeXY(int op, int *x, int *y){
	switch(op){
		case 0:
			*x -= 1;
			*y -= 2;
		break;
		
		case 1:
			*x += 1;
			*y -= 2;
		break;
		
		case 2:
			*x += 2;
			*y -= 1;
		break;
		
		case 3:			
			*x += 2;
			*y += 1;
		break;
		
		case 4:
			*x += 1;
			*y += 2;
		break;
		
		case 5:
			*x -= 1;
			*y += 2;
		break;
		
		case 6:
			*x-= 2;
			*y += 1;
		break;
				
		case 7:
			*x -= 2;
			*y -= 1;
		break;	
	}
}

void voltarXY(int op, int *x, int *y){
	switch(op){
		case 0:
			*x += 1;
			*y += 2;
		break;
		
		case 1:
			*x -= 1;
			*y += 2;
		break;
		
		case 2:
			*x -= 2;
			*y += 1;
		break;
		
		case 3:			
			*x -= 2;
			*y -= 1;
		break;
		
		case 4:
			*x -= 1;
			*y -= 2;
		break;
		
		case 5:
			*x += 1;
			*y -= 2;
		break;
		
		case 6:
			*x += 2;
			*y -= 1;
		break;
				
		case 7:
			*x += 2;
			*y += 1;
		break;	
	}
}

void systempause() {
	printf("Next round?\n");
	char ch;
	scanf("%c", &ch);
}

int main(int argc, char **argv){
	int board[8][8];
	initBoard(board);
	
	system("clear");
	int rounds = 0;	
	printBoard(rounds, board);
	rounds++;
	
	int x = 0, y = 0;
	printf("Digit the initial position:\n");
	scanf("%i %i", &x, &y);
	board[x][y] = rounds;
	printBoard(rounds, board);
	
	while(rounds < 65){
		int vector[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		plays(x,y, board, &vector);
		int op = minor(vector);
		
		changeXY(op, &x, &y);		
	
		rounds++;
		if(rounds == 64){
			int i, j;
			for(i = 0; i < 8; i++){
				for(j = 0; j < 8; j++){
					if(board[i][j] == 0){
						board[i][j] = 64;
					}
				}
			}
			printBoard(rounds, board);
			printf("\n\n***********END***********\n");
			return 0;
		}	
		
		board[x][y] = rounds;
		printf("(%i,%i)\n", x,y);
		printBoard(rounds, board);
		//systempause();
	}
	return 0;
}