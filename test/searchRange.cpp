// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

//  

// 示例 1：

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]
// 示例 2：

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]
// 示例 3：

// 输入：nums = [], target = 0
// 输出：[-1,-1]

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int middle;
        int resl=-1,resr=-1;
        vector<int> res;
        while (left<=right)
        {
            middle = (left+right)/2;
            if (target==nums[middle])
            {
                resr=resl=middle;
                break;
            }else if (target>=nums[middle])
            {
                left=middle+1;
            }else{
                right=middle-1;
            }
            
        }
        while (resr<nums.size()-1&&nums[resr+1]==target)
        {
            resr++;
        }
        while (resl>0&&nums[resl-1]==target)
        {
            resl--;
        }
        res.push_back(resl);
        res.push_back(resr);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    Solution s;
    for (auto &&i : s.searchRange(nums,target))
    {
        cout<<i;
    }
     
    return 0;
}
