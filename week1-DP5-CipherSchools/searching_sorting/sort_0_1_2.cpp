#include <bits/stdc++.h>
using namespace std;

void sort_0_1_2(vector<int> &nums)
{
    int p0 = 0, p1 = 0, p2 = nums.size() - 1;
    while (p1 <= p2)
    {
        switch (nums[p1])
        {
        case 0:
            swap(nums[p0], nums[p1]);
            p0++;
            p1++;
            break;
        case 1:
            p1++;
            break;
        case 2:
            swap(nums[p1], nums[p2]);
        p2--;
            break;
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort_0_1_2(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] <<" ";
    }
}