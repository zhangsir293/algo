// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

//  

// 示例 1:

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:

// 输入: nums = [1], k = 1
// 输出: [1]
//  

// 提示：

// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
//  

// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};


// class Solution {
// public:

//     static bool cmp(pair<int, int>& m, pair<int, int>& n) {
//             return m.second > n.second;
//         }

//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> res;
//         unordered_map<int,int> mp;
//         for (auto &&i : nums)
//         {
//             if (!mp.count(i))
//             {
//                 mp[i]=1;
//             }else{
//                 mp[i]++;
//             }
            
//         }
//         // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
//         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
//         for (auto& [num, count] : mp) {
//             if (q.size() == k) {
//                 if (q.top().second < count) {
//                     q.pop();
//                     q.emplace(num, count);
//                 }
//             } else {
//                 q.emplace(num, count);
//             }
//         }
//         vector<int> res;
//         while (!q.empty()) {
//             res.emplace_back(q.top().first);
//             q.pop();
//         }
//         resurn res;
//     }
// };

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    for (auto &&i : s.topKFrequent(nums,k))
    {
        cout<<i;
    }
    
    return 0;
}
