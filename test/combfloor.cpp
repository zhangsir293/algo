// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 

// 示例 1：

// 输入：n = 2
// 输出：2
// 解释：有两种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶
// 2. 2 阶
// 示例 2：

// 输入：n = 3
// 输出：3
// 解释：有三种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶 + 1 阶
// 2. 1 阶 + 2 阶
// 3. 2 阶 + 1 阶

#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    /* f(x)=f(x-1)+f(x-2) */
    int n=7,res=0;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for (int i = 3; i <= n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];

    return 0;
}
