#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/// 后序遍历 + 剪枝(从底至顶)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }

private:
    int recur(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = recur(root->left);
        if (left == -1)
            return -1;

        int right = recur(root->right);
        if (right == -1)
            return -1;

        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};

#elif 1
/// 先序遍历 + 判断深度(从顶至底)
// 三种遍历方式都可以,但是相比于第一种(二叉树只遍历一次,记录深度值),不管是那种遍历方式,depth()都会遍历二叉树多次
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        // 先序遍历
        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
        // 后序遍历
        // return isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) < 2;
        // 中序遍历
        // return isBalanced(root->left) && abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->right);
    }

private:
    int depth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
#endif

// 生成二叉树: 使用队列(先进先出)
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
    vector<int> nums = {5,3,6,2,4,NULL,NULL,1};
    TreeNode *tree = createTree(nums);

    Solution solve;
    cout << "res = " << solve.isBalanced(tree) << endl;

    cout << "\nFinish";
    return 0;
}
