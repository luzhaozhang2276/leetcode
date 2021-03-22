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
class Solution {
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);

        return res;
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}