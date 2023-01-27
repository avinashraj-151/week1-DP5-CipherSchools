#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size() - 1;
    if (row < 0)
    {
        return false;
    }

    int c = matrix[0].size() - 1;
    int r = 0;
    while (c >= 0 && r <= row)
    {
        if (target == matrix[r][c])
        {
            return true;
        }
        else if (target < matrix[r][c])
        {
            c--;
        }
        else if (target > matrix[r][c])
        {
            r++;
        }
    }
    return false;
}

int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >>matrix[i][j];
        }
    }
    int target;
    cin >> target;
    cout<<searchMatrix(matrix, target);
}