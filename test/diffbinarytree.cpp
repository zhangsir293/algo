// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

//  

// 示例 1：


// 输入：n = 3
// 输出：5
// 示例 2：

// 输入：n = 1
// 输出：1
//  

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numTrees1(int n) {
        vector<int> nt(n+1,0);
        nt[0]=1;
        nt[1]=1;
        //笛卡尔积
        for (size_t i = 2; i <= n; i++)
        {
            for (size_t j = 1; j <= i; j++)
            {
                nt[i]+=nt[j-1]*nt[i-j];
            }
            
        }
        return nt[n];
    }

    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

int main(int argc, char const *argv[])
{
    int n=3;
    Solution s;
    cout<<s.numTrees(n);
    return 0;
}
