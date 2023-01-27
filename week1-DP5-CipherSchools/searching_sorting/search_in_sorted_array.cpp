#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (nums[mid] == target)
    {
        return mid;
    }

    if (nums[start] <= nums[mid])
    {
        if (nums[start] <= target && target < nums[mid])
        {
            return search(nums, start, mid - 1, target);
        }
        else
        {
            return search(nums, mid + 1, end, target);
        }
    }
    else
    {
        if (nums[mid] < target && target <= nums[end])
        {
            return search(nums, mid + 1, end, target);
        }
        else
        {
            return search(nums, start, mid - 1, target);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        nums[i] = x;
    }
    int target;
    cin>>target;
    cout<<search(nums, 0, nums.size()-1,target);
}