// 给定一个二叉树，找出其最大深度。

// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

// 说明: 叶子节点是指没有子节点的节点。

// 示例：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

#include<iostream>
#include<vector>
#include<queue>

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
    int maxDepth(TreeNode* root) {
        if (root==nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }

    int maxDepth2(TreeNode* root) {
        if (root==nullptr)
        {
            return 0;
        }
        queue<TreeNode*> q;
        int res=0;
        q.push(root);
        
        while (!q.empty())
        {
            //当前这一层的节点个数
            int sz=q.size();
            while (sz>0)
            {
                TreeNode *cur=q.front();
                q.pop();
                sz--;
                if (cur->left)
                {
                    q.push(cur->left);
                    // sz++;
                }
                if (cur->right)
                {
                    q.push(cur->right);
                    // sz++;
                }
            }
            res++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums={3,9,20,NULL,NULL,15,7};
    TreeNode* root,*cur;
    root=cur=new TreeNode(3);
    cur->left=new TreeNode(9);
    cur->right=new TreeNode(20);
    cur=cur->right;
    cur->left=new TreeNode(15);
    cur->right=new TreeNode(7);
    Solution s;
    cout<<s.maxDepth2(root);
    
    return 0;
}

