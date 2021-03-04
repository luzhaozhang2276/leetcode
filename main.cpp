#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        recur(root);
        return res;
    }

private:
    int k, res;
    void recur(TreeNode *root) {
        if (root == nullptr)
            return;

        recur(root->right);

        if (k == 0)     // 提前返回
            return;
        if (--k == 0)
            res = root->val;

        recur(root->left);
    }
};

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
    cout << "num = " << solve.kthLargest(tree, 3) << endl;

    cout << "\nFinish";
    return 0;
}
