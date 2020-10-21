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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if (preorder == nullptr || inorder == nullptr)
        // return nullptr;
        return buildCore(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildCore(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd ) {
#if 0
        // 先序遍历创建根节点
        int rootValue = *preBegin;
        TreeNode* root = new TreeNode(rootValue);

        // 若仅有一个数据
        if (preBegin == preEnd)
        {
            if (inBegin == inEnd && *preBegin == *inBegin)
                return root;
        }

        // 多个数据,中序遍历找根节点
        auto rootInorder = inBegin;
        while (rootInorder <= inEnd && *rootInorder != rootValue)
            ++rootInorder;
        cout << *rootInorder << endl;

        // 遍历构建左右子树
        int leftLength = rootInorder - inBegin;
        auto leftEnd = inBegin + leftLength;
        if (leftLength > 0)     // 左子树
            root->left = buildCore(preBegin+1, preBegin+(rootInorder - inBegin), inBegin, rootInorder);
        if (leftLength < preEnd - preBegin)       // 右子树
            root->right = buildCore(preBegin+(rootInorder - inBegin)+1, preEnd, rootInorder+1, inEnd);
#else

        if(inEnd == inBegin)
            return NULL;
        TreeNode* root = new TreeNode(*preBegin);
        auto rootInorder = find(inBegin, inEnd, *preBegin);
        root->left = buildCore(preBegin+1, preBegin+(rootInorder - inBegin), inBegin, rootInorder);
        root->right = buildCore(preBegin+(rootInorder - inBegin)+1, preEnd, rootInorder+1, inEnd);
#endif
        return root;
    }
};

int main() {
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    TreeNode* reTree = s.buildTree(preorder, inorder);

    cout << "\nFinish" << endl;
    return 0;
}
