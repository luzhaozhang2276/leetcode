#include <bits/stdc++.h>
using namespace std;

/// 剑指 Offer 68 - II. 二叉树的最近公共祖先

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 终止条件: 叶子节点 or 找到 p q
        if (root == nullptr || root == p || root == q)
            return root;

        // 递归调用左右节点
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        // if (left == nullptr && right == nullptr)         // 均为空
        //     return nullptr;
        if (left == nullptr)        // 左空右不空
            return right;
        if (right == nullptr)   // 左非空右空
            return left;

        return root;                // 均非空, 即p = q = root
    }
};



int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}