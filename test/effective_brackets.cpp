// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。
 

// 示例 1：

// 输入：s = "()"
// 输出：true
// 示例 2：

// 输入：s = "()[]{}"
// 输出：true

#include<string>
#include<iostream>
#include<stack>
#include<unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    string s="()[]{}";
    unordered_map<char,char> map = {
        {')','('},
        {']','['},
        {'}','{'}
    };

    stack<char> stk;

    for (auto &&ch : s)
    {
        if (map.count(ch))
        {
            if (stk.empty()||stk.top()!=map[ch])
            {
                return -1;
            }
            stk.pop();
        }else{
            stk.push(ch);
        }
        
    }

    int res = stk.empty()?1:-1;
    cout<<res;
    
    return 0;
}
