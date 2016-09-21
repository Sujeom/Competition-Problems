/*bunnies.c by Josue Martinez 
COP3502 Dr.Elva 03/16/2016*/

#include <stdio.h>
#include <stdlib.h>

const int DX_SIZE = 4;/*for the 4 direction either Petter or Cottontail can move*/
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

char** build2DArray(char **, int, int);
void free2DArray(char**, int);
void buildMaze(char**, int, int);
void sectionCheck(char**, int , int);
void findPeter(char **maze, int row, int col, int *loca1, int *loca2);
void findCotton(char **maze, int row, int col, int *loca1, int *loca2);
void floodfill(char**, int, int, int, int);

int main()
{
	int i;
	int cases;/*for the number of times the program will loop*/
	int r, c;/*r and c for rows and colums of maze respectivly*/
	char **maze;/*for the layout of the maze*/
	
	scanf("%d", &cases);
	
	while(cases > 0)
	{
		do
		{
			scanf("%d %d", &r, &c);
		}while(r < 1 || c > 10 || c < 1);
		
maze = build2DArray(maze, r, c);
		if(maze == NULL)
			{
				printf("error allocating memory");
				return 0;
			}
			
			buildMaze(maze, r, c);
			sectionCheck(maze, r, c);
 
		free2DArray(maze, r);
		
		cases--;
	}
	return 0;
}
/*---------------------------------*/
/*function to dynammically allocate memmory for a 2D array of chars*/
/*function will return 0 if there was an allocation error*/
char** build2DArray(char** x, int row, int col)
{
	int i;

	x = (char**) malloc(row*sizeof(char*));

	for(i = 0; i < row; i++)
	{
		x[i] = (char*) malloc((col + 1)*sizeof(char));
	}
return x;
	/*if(x == NULL)
		return 0;
	else
		return 1;*/
}
/*---------------------------------*/
/*function to free memory allocated for a 2D array*/
void free2DArray(char ** x, int size)
{
	int i;

	for(i = 0; i < size; i++)
		free(x[i]);
	free(x);
}
/*--------------------------------*/
/*function for user to build maze for currect case*/
void buildMaze(char ** x, int rows, int cols)
{
	int i;
	for(i = 0; i < rows; i++)
			scanf("%s", &x[i][0]);
}
/*-------------------------------*/
/*function to check if peter and cottontail are in the same section*/
void  sectionCheck(char ** maze, int rows, int cols)
{
	int i, sameSection = 0,x,y;
/*for the row and column location of peter*/
	int locaPRow, locaPCol;
	/*for the row and column location of cottontail*/
	int locaCRow, locaCCol;
	findPeter(maze, rows, cols, &locaPRow, &locaPCol);
	findCotton(maze, rows, cols, &locaCRow, &locaCCol);
	floodfill(maze, rows, cols, locaPRow, locaPCol);
	
	if(maze[locaCRow][locaCCol] == '-')
		printf("yes\n");
	else
		printf("no\n");
	
}
/*--------------------------------*/
/*finds the index where peter is at*/
void findPeter(char **maze, int row, int col, int *loca1, int *loca2)
{
	int i, j;
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++)
			if(maze[i][j] == 'P')
			{
				*loca1 = i;
				*loca2 = j;
				return;
			} 
}
/*--------------------------------*/
/*finds the index where Cottontail is at*/
void findCotton(char **maze, int row, int col, int *loca1, int *loca2)
{
	int i, j;
	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++)
			if(maze[i][j] == 'C')
			{
				*loca1 = i;
				*loca2 = j;
	return;
			} 
}
/*--------------------------------*/
/*floodfill function to solve the problem of moving bunny*/
void  floodfill(char **maze, int rows, int cols, int x, int y)
{
	int i;
	
	if(x < 0 || x >= rows|| y < 0 || y >= cols)
		return;
		
	if(maze[x][y] == '#' || maze[x][y] == '-')
		return;
			
	maze[x][y] = '-';

	floodfill(maze, rows, cols, x + DX[0], y + DY[0]);
	floodfill(maze, rows, cols, x + DX[1], y + DY[1]);
	floodfill(maze, rows, cols, x + DX[2], y + DY[2]);
	floodfill(maze, rows, cols, x + DX[3], y + DY[3]);

	
}
