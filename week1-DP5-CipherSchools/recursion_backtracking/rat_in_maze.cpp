#include <bits/stdc++.h>
using namespace std;

int possibleMoves = 4;
int xMov[] = {1, -1, 0, 0};
int yMov[] = {0, 0, 1, -1};

bool isSafe(vector<vector<bool>> &maze, vector<vector<bool>> &visited, int r, int c, int R, int C)
{
    return (r >= 0 && r < R && c >= 0 && c < C && maze[r][c] && !visited[r][c]);
}

bool ratIntheMazeHelper(vector<vector<bool>> &maze, vector<vector<bool>> &visited, int r, int c, int R, int C)
{
    if (r == R - 1 && c == C - 1 && maze[r][c])
    {
        visited[r][c] = true;
        return true;
    }
    
    if (isSafe(maze, visited, r, c, R, C))
    {
        visited[r][c] = true;
        for (int i = 0; i < possibleMoves; i++)
        {
            int nextXMove = r + xMov[i];
            int nextYMove = c + yMov[i];
            if (ratIntheMazeHelper(maze, visited, nextXMove, nextYMove, R, C))
            {
                return true;
            }
        }
        visited[r][c] = false;
        return false;
    }

    return false;
}
void rat_maze(vector<vector<bool>>& maze)
{
    int R = maze.size();
    if (R == 0)
    {
        // ask interviewer
        return;
    }
    int C = maze[0].size();
    vector<vector<bool>> visited(C, vector<bool>(C, false));
    if (ratIntheMazeHelper(maze, visited, 0, 0, R, C))
    {
        cout << "Found the path\n";
        for (vector<bool> r : visited)
        {
            for (bool b : r)
            {
                cout << (b == true ? 1 : 0) << "\t";
            }
            cout << "\n";
        }
    } else {
        cout << "No Paths Found\n";
    }
}
int main()
{
    vector<vector<bool>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    rat_maze(maze);

    return 0;
}