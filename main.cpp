#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/// 递归
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        // if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        if (root == nullptr)
            return root;

        TreeNode* ptmp = root->left;
        root->left = root->right;
        root->right = ptmp;

        if (root->left != nullptr)
            mirrorTree(root->left);

        if (root->right != nullptr)
            mirrorTree(root->right);

        return root;
    }
};

#elif 0
/// 辅助栈
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            if (node->left != nullptr)
                stack.push(node->left);
            if (node->right != nullptr)
                stack.push(node->right);

            TreeNode* ptmp = node->left;
            node->left = node->right;
            node->right = ptmp;
        }

        return root;
    }
};

#elif 1
/// 辅助队列
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty())
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            if (node->left != nullptr)
                nodeQueue.push(node->left);
            if (node->right != nullptr)
                nodeQueue.push(node->right);

            TreeNode* ptmp = node->left;
            node->left = node->right;
            node->right = ptmp;
        }

        return root;
    }
};
#endif

/// 生成二叉树: 使用队列(先进先出)
TreeNode* createTree(vector<int> &number)
{
    if (number.empty())
        return nullptr;

    auto ptr = number.begin();

    TreeNode* root = new TreeNode(*ptr);
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (ptr != number.end())
    {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        ptr++;
        if(ptr != number.end() && *ptr != '\0') {
            node->left = new TreeNode(*ptr);
            nodeQueue.push(node->left);
        }

        if(ptr == number.end())
            break;

        ptr++;
        if(ptr != number.end() && *ptr != '\0')
        {
            node->right = new TreeNode(*ptr);
            nodeQueue.push(node->right);
        }
    }

    return root;
}

int main() {
    /// 数据生成 ptr
    vector<int> A = {4,2,7,1,3,6,9};
//    vector<int> A = {4,'\0',1,2,3};
    TreeNode* treeA = createTree(A);

    Solution solve;
    solve.mirrorTree(treeA);


    cout << "\nFinish" << endl;
    return 0;
}
