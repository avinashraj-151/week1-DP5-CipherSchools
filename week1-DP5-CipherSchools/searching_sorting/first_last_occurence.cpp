#include <bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;
    if (start == end)
    {
        return (target == nums[start] ? start : -1);
    }
    int mid = start + (end - start) / 2;

    if (nums[mid] == target)
    {
        if ((mid == 0) || (mid - 1 >= 0 && nums[mid] > nums[mid - 1]))
            return mid;
        else
        {
            return firstOccurrence(nums, start, mid - 1, target);
        }
    }
    else if (nums[mid] < target)
    {

        return firstOccurrence(nums, mid + 1, end, target);
    }
    else
    {
        return firstOccurrence(nums, start, mid - 1, target);
    }
}

int lastOccurrence(vector<int> &nums, int start, int end, int target)
{
        if (start > end)
            return -1;
        if (start == end)
        {
            return (target == nums[start] ? start : -1);
        }
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            if ((mid == end) || (mid + 1 <= end && nums[mid] < nums[mid + 1]))
                return mid;
            else
            {
                return lastOccurrence(nums, mid + 1, end, target);
            }
        }
        else if (nums[mid] < target)
        {
            return lastOccurrence(nums, mid + 1, end, target);
        }
        else
        {
            return lastOccurrence(nums, start, mid - 1, target);
        }
}
vector<int> searchRange(vector<int> &nums, int target)
{
        int first = firstOccurrence(nums, 0, nums.size() - 1, target);
        int last = lastOccurrence(nums, 0, nums.size() - 1, target);
        return {first, last};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}