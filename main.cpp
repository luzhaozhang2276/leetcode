#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
/// 迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (root->val < p->val && root->val < q->val)
                root = root->right;
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else break;
        }
        return root;
    }
};

#elif 0
/// 迭代 (减少判断次数)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) { // 保证 p.val < q.val
            TreeNode* tmp = p;
            p = q;
            q = tmp;
        }

        while (root != nullptr) {
            if (root->val < p->val)
                root = root->right;
            else if (root->val > q->val)
                root = root->left;
            else break;
        }
        return root;
    }
};

#elif 1
/// 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
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