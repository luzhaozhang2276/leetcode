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

/// 104. 二叉树的最大深度
#if 1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

#elif 1
class Solution {
    int deep = 0;
    int recurve(TreeNode* root, int level) {
        if (root == nullptr)
            return level;

        deep = max(deep, recurve(root->left, level+1));
        deep = max(deep, recurve(root->right, level+1));
        return level + 1;
    }
public:
    int maxDepth(TreeNode* root) {
        deep = max(deep, recurve(root, 0));
        return deep;
    }
};
#endif

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}