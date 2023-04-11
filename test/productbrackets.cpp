// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]
 

// 提示：

// 1 <= n <= 8

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size()==2*n)
        {
            ans.push_back(cur);
            return;
        }
        if (open<n)
        {
            cur.push_back('(');
            backtrack(ans,cur,open+1,close,n);
            cur.pop_back();
        }
        if (open>close)
        {
            cur.push_back(')');
            backtrack(ans,cur,open,close+1,n);
            cur.pop_back();
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        int open=0,close=0;
        backtrack(res,cur,open,close,n);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> res=s.generateParenthesis(3);
    for (auto &&i : res)
    {
     cout<<i<<endl;   
    }
    
    return 0;
}
