// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
// 滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

//  

// 示例 1：

// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < k; i++)
        {
           q.emplace(nums[i],i);
        }

        res.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            q.emplace(nums[i],i);
            while (q.top().second <= i-k)
            {
                q.pop();
            }
            res.push_back(q.top().first);
            
        }
        
        
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int k=3;
    vector<int> res;
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    res = s.maxSlidingWindow(nums,k);
    for (auto &&i : res)
    {
        cout<<i;
    }
    
    //超时
    // vector<int> nums = {1,-1};
    // int k=1;
    // vector<int> res;

    // if (k==1)
    // {
    //     res=nums;
    // }
    
    
    // for (int i = 0; i < nums.size()-k+1; i++)
    // {
    //     int maxtmp=INT32_MIN;
    //     for (int j = 0; j < k; j++)
    //     {
    //         maxtmp=max(maxtmp,nums[i+j]);
    //     }
        
    //     res.push_back(maxtmp);
    // }

    // for (size_t i = 0; i < res.size(); i++)
    // {
    //     cout<<res[i];
    // }
    
    
    return 0;
}

