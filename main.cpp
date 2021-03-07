#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/// 后序遍历DFS (左右根)
// 简化版本
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        return root;
    }
};

#elif 1
/// 后序遍历DFS (左右根)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr && right == nullptr)    // 1. 同时为空: 说明左右子树都不包含p,q,返回nullptr
            return nullptr;
        if (left == nullptr)    // 3. 均不在left,返回right
            return right;
        if (right == nullptr)   // 4. 均不在right,返回left
            return left;

        return root;        // 2. 同时不为空: 说明在异侧,此时的root即为最近公共祖先
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
    vector<int> nums = {6,2,8,0,4,7,9,NULL,NULL,3,5};
    TreeNode *tree = createTree(nums);


    Solution solve;
    cout << "res = " << solve.lowestCommonAncestor(tree, tree->left->right, tree->right)->val << endl;

    cout << "\nFinish";
    return 0;
}