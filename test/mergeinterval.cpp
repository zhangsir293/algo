// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

//  

// 示例 1：

// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2：

// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==0)
        {
            /* code */
            return {};
        }
        
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for (int i = 0; i < intervals.size(); i++)
        {
            int L=intervals[i][0],R=intervals[i][1];
            if (res.size()==0||L>res.back()[1])
            {
                res.push_back({L,R});
                continue;
            }
            res.back()[1]=max(R,res.back()[1]);
            // res.push_back({L,max(R,res.back()[1])});
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> res;
    vector<vector<int>> internals={{1,3},{2,6},{8,10},{15,18}};
    res=s.merge(internals);

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

