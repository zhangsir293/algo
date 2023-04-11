// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 

// 示例 1 ：

// 输入：nums = [2,2,1]
// 输出：1
// 示例 2 ：

// 输入：nums = [4,1,2,1,2]
// 输出：4
// 示例 3 ：

// 输入：nums = [1]
// 输出：1

#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums={4,1,2,1,2};
    // unordered_set<int> set;

    // for (auto &&i : nums)
    // {
    //     if (set.count(i))
    //     {
    //         set.erase(i);
    //         continue;
    //     }
    //     set.insert(i);
    // }
    // cout<<*set.begin();

    int ret = 0;
    //位运算永远的神，任何数抑或自身等于0，任何数抑或0等于自身
    for (auto e: nums) ret ^= e;
    return ret;
    return 0;
}