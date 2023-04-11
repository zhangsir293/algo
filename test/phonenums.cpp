// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。


// 示例 1：

// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：

// 输入：digits = ""
// 输出：[]
// 示例 3：

// 输入：digits = "2"
// 输出：["a","b","c"]

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> res;
       if (digits.empty())
       {
        return res;
       }
       unordered_map<char,string> phoneMap{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
       };
       string combination;
       backtrack(res,phoneMap,digits,0,combination);
       return res;
    }

    void backtrack(vector<string>& res,const unordered_map<char,string>& phoneMap,const string& digits, int index, string& combination){
        if (index==digits.size())
        {
            res.push_back(combination);
            return;
        }
        char digit = digits[index];
        const string& letters=phoneMap.at(digit);
        for (int i = 0; i < letters.size(); i++)
        {
            combination.push_back(letters[i]);
            backtrack(res,phoneMap,digits,index+1,combination);
            combination.pop_back();
        }
        
    }
};

int main(int argc, char const *argv[])
{
    string digits = "23";
    vector<string> res;
    Solution s;
    res=s.letterCombinations(digits);
    for (auto &&i : res)
    {
        cout<<i<<endl;
    }
    
    return 0;
}
