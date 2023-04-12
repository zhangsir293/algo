// 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

//  

// 示例 :
// 给定二叉树

//           1
//          / \
//         2   3
//        / \     
//       4   5    
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

#include<vector>
#include<iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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
        int l=dfs(root->left);
        int r=dfs(root->right);
        res=max(l+r+1,res);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res=0;
        dfs(root);
        //需要把自己排除
        return res-1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={4,2,1,3,5};
    TreeNode* tn=new TreeNode(1);
    TreeNode* cur=tn;
    cur->left=new TreeNode(2);
    cur->right=new TreeNode(3);
    // cur=cur->left;
    // cur->left=new TreeNode(4);
    // cur->right=new TreeNode(5);

    Solution s;
    cout<<s.diameterOfBinaryTree(tn);
    return 0;
}
