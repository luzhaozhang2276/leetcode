#include <bits/stdc++.h>
using namespace std;

/// NC45. 实现二叉树先序中序后序遍历


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int> > res;
        preorder(root);
        middleorder(root);
        postorder(root);

        res.push_back(pre);
        res.push_back(middle);
        res.push_back(post);
        return res;
    }

private:
    vector<int> pre;
    vector<int> middle;
    vector<int> post;

    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;

        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    void middleorder(TreeNode* root) {
        if (root == nullptr)
            return;

        middleorder(root->left);
        middle.push_back(root->val);
        middleorder(root->right);
    }

    void postorder(TreeNode* root) {
        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        post.push_back(root->val);
    }
};


int main() {
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution solve;
    for (auto nums : solve.threeOrders(root)) {
        for (auto num : nums)
            cout << num << ' ';
        cout << endl;
    }

    cout << "\nFinish";
    return 0;
}