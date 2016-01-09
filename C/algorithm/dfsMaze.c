#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void mazeGenerator(char* maze, int row, int col);
void dfsMaze(int row, int col, char* maze, int nowRow, int nowCol, int* endRow, int* endCol);
int noEdge(int row, int col, char* maze, int nowRow, int nowCol);
void findStart(int row, int col, char* maze, int* startRow, int* startColume);
void mazeTraverse(char* maze, int row, int col, int startRow, int startColume);
int dfsOut(int row, int col, char* maze, int end_r, int end_c, int startRow, int startColume, int* path);
void printMaze(char* maze, int row, int col, int now, int* path);
void flash(char* maze, int row, int col, int now, int* path);

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	int row = 31, col = 31;
	char maze[row*col];
	mazeGenerator(maze, row, col);
	mazeTraverse(maze, row, col, 0, 0);
	return 0;
}

void mazeGenerator(char* maze, int row, int col) {
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			maze[i*col+j] = '#';
		}
	}
	int startRow, startCol;
	switch (rand() % 4) {
		case 0:
			startRow = 0; startCol = rand() % (col-2) + 1; break;
		case 1:
			startRow = rand() % (row-2) + 1; startCol = 0; break;
		case 2:
			startRow = row-1; startCol = rand() % (col-2)+1; break;
		case 3:
			startRow = rand() % (row-2)+1; startCol = col-1; break;
	}
	int endRow, endCol;
	dfsMaze(row, col, maze, startRow, startCol, &endRow, &endCol);
	maze[endRow*col+endCol] = '.';
	return;
}

void dfsMaze(int row, int col, char* maze, int nowRow, int nowCol, int* endRow, int* endCol)
{
	maze[nowRow*col+nowCol] = '.';
	int path[5000] = {0};
	printMaze(maze, row, col, nowRow*col+nowCol, path);
	system("sleep 0.01");
	int dir_r[] = {1, 0, -1, 0};
	int dir_c[] = {0, 1, 0, -1};
	for (size_t i = 0; i < 4; i++) {
		if (nowRow+dir_r[i] == 0 || nowRow+dir_r[i] == row-1 ||
		nowCol+dir_c[i] == 0 || nowCol+dir_c[i] == col-1) {
			*endRow = nowRow+dir_r[i];
			*endCol = nowCol+dir_c[i];
		}
	}
	int direction;
	int check[4] = {1, 1, 1, 1};
	do {
		direction = rand() % 4;
		if (check[direction] &&
		maze[(nowRow+dir_r[direction])*col+nowCol+dir_c[direction]] == '#' &&
		nowRow+dir_r[direction] > 0 && nowRow+dir_r[direction] < row-1 &&
		nowCol+dir_c[direction] > 0 && nowCol+dir_c[direction] < col-1 &&
		noEdge(row, col, maze, nowRow+dir_r[direction], nowCol+dir_c[direction])) {
			dfsMaze(row, col, maze, nowRow+dir_r[direction], nowCol+dir_c[direction], endRow, endCol);
		}
		check[direction] = 0;
	}
	while (!(check[0] == 0 && check[1] == 0 && check[2] == 0 && check[3] == 0));
	return;
}

int noEdge(int row, int col, char* maze, int nowRow, int nowCol)
{
	int count = 0;
	int dir_r[] = {1, 0, -1, 0};
	int dir_c[] = {0, 1, 0, -1};
	for (size_t i = 0; i < 4; i++) {
		if (maze[(nowRow+dir_r[i])*col+nowCol+dir_c[i]] == '.') count++;
		if (count > 1) {
			return 0;
		}
	}
	return 1;
}

void findStart(int row, int col, char* maze, int* startRow, int* startColume)
{
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			if (maze[i*col+j] == '.' && (i == 0 || i == row-1 || j == 0 || j == col-1)) {
				*startRow = i;
				*startColume = j;
				return;
			}
		}
	}
	return;
}

void mazeTraverse(char* maze, int row, int col, int startRow, int startColume)
{
	findStart(row, col, maze, &startRow, &startColume);
	int path[1000] = {0};
	path[startRow*col+startColume] = 1;
	if (dfsOut(row, col, maze, startRow, startColume, startRow, startColume, path))
		printf("Success!\n");
	else
		printf("Fail!\n");
	return;
}

int dfsOut(int row, int col, char* maze, int startRow, int startColume, int nowRow, int nowCol, int* path)
{
	maze[nowRow*col+nowCol] = 'x';
	printMaze(maze, row, col, nowRow*col+nowCol, path);
	system("sleep 0.05");
	if ((nowRow == 0 || nowCol == 0 || nowRow == row-1 || nowCol == col-1) &&
	(nowRow != startRow || nowCol != startColume)) return 1;
	int dir_r[] = {1, 0, -1, 0};
	int dir_c[] = {0, 1, 0, -1};
	for (size_t i = 0; i < 4; i++) {
		if (maze[(nowRow+dir_r[i])*col+nowCol+dir_c[i]] == '.') {
			path[(nowRow+dir_r[i])*col+nowCol+dir_c[i]] = 1;
			if(dfsOut(row, col, maze, startRow, startColume, nowRow+dir_r[i], nowCol+dir_c[i], path)) {
				flash(maze, row, col, nowRow*col+nowCol, path);
				return 1;
			}
			path[(nowRow+dir_r[i])*col+nowCol+dir_c[i]] = 0;
		}
	}
	return 0;
}

void printMaze(char* maze, int row, int col, int now, int* path)
{
	system("clear");
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			if (i*col+j == now)
				printf("%s%c ", KMAG, maze[i*col+j]);
			else if (path[i*col+j])
				printf("%s%c ", KGRN, maze[i*col+j]);
			else if (maze[i*col+j] == 'x')
				printf("%s%c ", KYEL, maze[i*col+j]);
			else if (maze[i*col+j] == '.')
				printf("%s%c ", KWHT, maze[i*col+j]);
			else
				printf("%s%c ", KCYN, maze[i*col+j]);
		}
		printf("\n");
	}
	return;
}

void flash(char* maze, int row, int col, int now, int* path)
{
	for (size_t t = 0; t < 1; t++) {
		printMaze(maze, row, col, now, path);
		system("sleep 0.3");
		system("clear");
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (i*col+j == now)
					printf("%s%c ", KMAG, maze[i*col+j]);
				else if (path[i*col+j])
					printf("  ");
				else if (maze[i*col+j] == 'x')
					printf("%s%c ", KYEL, maze[i*col+j]);
				else if (maze[i*col+j] == '.')
					printf("%s%c ", KWHT, maze[i*col+j]);
				else
					printf("%s%c ", KCYN, maze[i*col+j]);
			}
			printf("\n");
		}
		system("sleep 0.2");
	}
	return;
}

