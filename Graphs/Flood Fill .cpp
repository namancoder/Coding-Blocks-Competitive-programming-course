#include <bits/stdc++.h>
using namespace std;

/*

15 30
..............................
.............#####............
.............#...#............
.....#########...#######......
....###.....######.....###....
...##....................##...
..##......................#...
..##.....................##...
..###...................##....
....###................###....
......###............###......
........###........###........
..........##########..........
..............................
...........A.P.P.L.E..........


Sample Input Parameters
*/
int R, C;

void printMat(char input[][50])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << input[i][j] << "";
        }
        cout << endl;
    }
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void floodFill(char mat[][50], int i, int j, char ch, char colour)
{
    //BAse Case
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }

    //figure Boundary Condition
    if (mat[i][j] != ch)
        return;

    //Recursive Call;
    mat[i][j] = colour;
    for (int k = 0; k < 4; k++)
    {
        floodFill(mat, i + dx[k], j + dy[k], ch, colour);
    }
}
int main()
{
    cin >> R >> C;
    char input[15][50];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> input[i][j];
        }
    }

    //printMat(input);
    floodFill(input, 8, 13, '.', 'r');
    printMat(input);
}