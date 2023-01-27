#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 1)
    {
    return;
    }
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (i = 0; i < n; i++)
    {
        j = 0, k = n - 1;
        while (j < k)
        {
            swap(matrix[i][j], matrix[i][k]);
            j++;
            k--;
        }
    }
}
int main(){
    vector<vector<int> > nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(nums);
    for(int i = 0; i < nums.size();i++){
        for(int j = 0; j < nums[i].size();j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
