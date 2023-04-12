// 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标。

//  

// 示例 1：

// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
// 示例 2：

// 输入：nums = [3,2,1,0,4]
// 输出：false
// 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length=nums.size();
        // if (length==1)
        // {
        //     return true;
        // }
        
        int mostright=0;
        for (int i = 0; i < length; i++)
        {
            if (i<=mostright)
            {
                mostright=max(mostright,nums[i]+i);
            }
            if (mostright>=length-1)
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={2,3,1,1,4};
    Solution s;
    cout<<s.canJump(nums);
    return 0;
}
