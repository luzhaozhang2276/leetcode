#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// 114. 二叉树展开为链表
// 寻找当前节点的前驱结点
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            auto pre = root->left;
            while (pre->right != nullptr) pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        root = root->right;
        return;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);

    Solution s;


    cout << "\nFinish" << endl;
    return 0;
}
