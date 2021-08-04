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

/// 101. 对称二叉树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return true;

        if (root->left == nullptr || root->right == nullptr)
            return false;

        return root->left->val == root->right->val &&
               isSymmetric(root->left) && isSymmetric(root->right);
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}