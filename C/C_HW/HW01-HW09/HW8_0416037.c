#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COL 20

void init_map(char map[ROW][COL]);
int mother_fly(char map[ROW][COL], int start);
int child_fly(char map[ROW][COL], int end);
void print_map(char map[ROW][COL]);

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  char map[ROW][COL];
  init_map(map);
  int start = rand() % COL * ROW;
  int end = mother_fly(map, start);
  print_map(map);
  if(child_fly(map, end)) printf("Yes\n");
  else printf("No\n");
  return 0;
}

void init_map(char map[ROW][COL])
{
  int i,j;
  char c;
  for (size_t i = 0; i < ROW; i++) {
    for (size_t j = 0; j < COL; j++) {
      c=(map[i][j] = '#');
    }
  }
  return;
}

int mother_fly(char map[ROW][COL], int start)
{
  int row = start / COL;
  int col = start % COL;
  int direction;
  char c;
  for (size_t c = 'A'; c <= 'Z'; c++) {
    int dir_row[4], dir_col[4];
    dir_row[0]=-1; dir_row[1]=1; dir_row[2]=0; dir_row[3]=0;
    dir_col[0]=0; dir_col[1]=0; dir_col[2]=-1; dir_col[3]=1;
    int check[4]={0};
    while (1) {
      direction = rand() % 4;
      if (row+dir_row[direction] >= 0 && row+dir_row[direction] < ROW &&
      col+dir_col[direction] >= 0 && col+dir_col[direction] < COL &&
      map[row+dir_row[direction]][col+dir_col[direction]] == '#') {
        row += dir_row[direction];
        col += dir_col[direction];
        map[row][col] = c;
        break;
      }
      else if( check[0]==1 && check[1]==1 && check[2]==1 && check[3]==1 ) return row*COL+col;
      check[direction]=1;
    }
  }
  return row*COL+col;
}

int child_fly(char map[ROW][COL], int end)
{
  int e_row = end / COL, e_col = end % COL;
  map[e_row][e_col] = '*';
  int dir_row[4], dir_col[4];
  dir_row[0]=-1; dir_row[1]=1; dir_row[2]=0; dir_row[3]=0;
  dir_col[0]=0; dir_col[1]=0; dir_col[2]=-1; dir_col[3]=1;
  int i;
  for (size_t i = 0; i < 4; i++) {
    if (e_row+dir_row[i] >= 0 && e_row+dir_row[i] < COL &&
    e_col+dir_col[i] >= 0 && e_col+dir_col[i] < COL &&
    (map[e_row+dir_row[i]][e_col+dir_col[i]] == 'A' ||
    map[e_row+dir_row[i]][e_col+dir_col[i]] == '#' &&
    child_fly(map, (e_row+dir_row[i])*COL+(e_col+dir_col[i])))) return 1;
  }
  return 0;
}

void print_map(char map[ROW][COL]) {
  int i, j, rowLimit = ROW, colLimit = COL;
  for (size_t i = 0; i < rowLimit; i++) {
    for (size_t j = 0; j < colLimit; j++) {
      if (j==colLimit-1) printf("%c\n", map[i][j]);
      else printf("%c", map[i][j]);
    }
  }
  return;
}
