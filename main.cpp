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

/// 102. 二叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr)
            que.push(root);

        vector<vector<int>> res;
        while (!que.empty()) {
            vector<int> curr;
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                auto p = que.front();
                que.pop();
                curr.push_back(p->val);
                if (!p->left)
                    que.push(p->left);
                if (!p->right)
                    que.push(p->right);
            }
            res.push_back(curr);
        }

        return res;
    }
};

int main() {
    Solution solve;

    cout << "\nFinish";
    return 0;
}