#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 1
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return recurtion(root, root);
    }

    bool recurtion(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr && pRoot2 == nullptr)
            return true;

        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        if (pRoot1->val != pRoot2->val)
            return false;

        return recurtion(pRoot1->left, pRoot2->right) && recurtion(pRoot1->right, pRoot2->left);
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
    vector<int> A = {1,2,2,3,4,4,3};
    TreeNode* treeA = createTree(A);

    Solution solve;
    string result = solve.isSymmetric(treeA) ? "True" : "False";
    cout << "result: " << result << endl;

    cout << "\nFinish" << endl;
    return 0;
}
