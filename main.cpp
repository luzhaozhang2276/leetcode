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

/// 98. 验证二叉搜索树
class Solution {
    long prev = LONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;

        if (!isValidBST(root->left))
            return false;

        if (root->val <= prev)
            return false;
        prev = root->val;

        return isValidBST(root->right);
    }
};

int main() {
    Solution solve;
    cout <<"res = " << solve.numTrees(4) << endl;

    cout << "\nFinish";
    return 0;
}