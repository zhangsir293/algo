// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：

// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for (int first = 0; first < n; first++)
        {
            if (first>0&&nums[first]==nums[first-1])
            {
                continue;
            }
            int target = -nums[first];
            int three = n-1;
            for (int second = first+1; second < n; second++)
            {
                if (second>first+1&&nums[second-1]==nums[second])
                {
                    continue;
                }
                while (second<three&&nums[second]+nums[three]>target)
                {
                    three--;
                }
                if (second==three)
                {
                    break;
                }
                if (nums[second]+nums[three]==target)
                {
                   res.push_back({nums[first],nums[second],nums[three]});
                }
                
            }
            
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res;
    Solution s;
    res = s.threeSum(nums);
    for (auto &&i : res)
    {
        for (auto &&j : i)
        {
            cout<<j;
        }
        cout<<endl;
    }
    
    
    return 0;
}
