#include <bits/stdc++.h>
using namespace std;

int rainwater(vector<int> &height)
{
    int n = height.size();
    vector<int> lMax(n), rMax(n);
    lMax[0] = height[0];
    rMax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
    {
        lMax[i] = max(height[i], lMax[i - 1]);
        rMax[n - i - 1] = max(height[n - i - 1], rMax[n - i]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
    ans += min(lMax[i], rMax[i]) - height[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin >> height[i];
    }
    cout<<rainwater(height)<<endl;
    return 0;
}