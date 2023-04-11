// 给你一个字符串 s，找到 s 中最长的回文子串。

// 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "babad";

    // if (s.size()<2)
    // {
    //     return s;
    // }
    

    int maxlen=1,begin=0,n=s.size();
    vector<vector<int>> dp(n,vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        /*长度为1的子串都是回文串 */
        dp[i][i]=1;
    }

    for (int L = 2; L <= n; L++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = L+i-1;
            if (j>=n)
            {
                break;
            }
            
            if (s[i]!=s[j])
            {
                dp[i][j]=-1;
            }
            else{
               if (j-i<3)
               {
                dp[i][j]=1;
               }
               else
               {
                dp[i][j]=dp[i+1][j-1];
               }
            }
            if (dp[i][j]>0&&j-i+1>maxlen)
            {
                maxlen = j-i+1;
                begin=i;
            }
            
        }
        
    }
    
    cout<<s.substr(begin,maxlen);
    return 0;
}
