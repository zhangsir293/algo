// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径
// 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

// 输入：root = [-10,9,20,null,null,15,7]
// 输出：42
// 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42

/**
 * Definition for a binary tree node.
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res;

    int dfs(TreeNode* root){
        if (root==nullptr)
        {
            return 0;
        }
        //左右子树各一个分支，所以当前节点的贡献值应该为左右子树的较大值与当前节点值的和
        int l=max(dfs(root->left),0);
        int r=max(dfs(root->right),0);
        int pathprice=l+r+root->val;
        res=max(res,pathprice);
        return max(l,r)+root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        res=INT_MIN;
        dfs(root);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* tn=new TreeNode(-10);
    TreeNode* cur=tn;
    cur->left=new TreeNode(9);
    cur->right=new TreeNode(20);
    cur=cur->right;
    cur->left=new TreeNode(15);
    cur->right=new TreeNode(7);
    Solution s;
    cout<<s.maxPathSum(tn);
    return 0;
}
