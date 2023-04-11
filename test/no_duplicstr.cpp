// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
#include<string>
#include<iostream>
#include<unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    string str="abcabcbb";
    unordered_set<char> occur;
    int rk=-1,n=str.size();
    int res = 0;
    // occur.insert(str[0]);
    // //find函数返回的是迭代器。解引用后返回元素
    // cout<<*occur.find('a')<<endl;
    // cout<<*occur.find('b')<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i!=0)
        {
            occur.erase(str[i-1]);
        }

        while (rk+1<n&&!occur.count(str[rk+1]))
        {
            occur.insert(str[rk+1]);
            rk=rk+1;
        }
        
        res=max(rk-i+1,res);
    }
    
    cout<<res;

    return 0;
}
