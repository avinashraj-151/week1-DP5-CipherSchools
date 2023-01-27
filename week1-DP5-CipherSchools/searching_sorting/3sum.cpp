#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        int curr1 = nums[i], start = i + 1, end = nums.size() - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (curr1 + nums[start] + nums[end] == 0)
            {
                res.push_back({curr1, nums[start], nums[end]});
                start++;
                end--;

                while (start < end && nums[start] == nums[start - 1])
                {
                    start++;
                }

                while (start < end && nums[end] == nums[end + 1])
                {
                    end--;
                }
            }
            else if (curr1 + nums[start] + nums[end] > 0)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        while (i < nums.size() - 1 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int> > ans = triplets(nums);
    for(auto val : ans){
        for(auto i : val){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}