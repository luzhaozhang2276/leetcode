#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/// 94. 二叉树的中序遍历
// 递归
class Solution {
    vector<int> res;
    void recurve(TreeNode* root) {
        if (root == nullptr)
            return;
        recurve(root->left);
        res.push_back(root->val);
        recurve(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        recurve(root);
        return res;
    }
};


int main() {

    Solution solve;

    cout << "\nFinish";
    return 0;
}