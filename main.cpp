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
    bool isSubStructure(TreeNode* A, TreeNode* B) {

        /// 常规写法
        /*
        bool result = false;

        if (A != nullptr && B != nullptr)
        {
            if (A->val == B->val)
                result = recursion(A, B);
            if (!result)
                result = isSubStructure(A->left, B);
            if (!result)
                result = isSubStructure(A->right, B);
        }
        return result;
         */

        /// 简略写法
        return (A != nullptr && B != nullptr) &&
               (recursion(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool recursion(TreeNode* A, TreeNode* B)
    {
        if (B == nullptr)
            return true;

        if (A == nullptr || A->val != B->val)
            return false;

        return recursion(A->left, B->left) && recursion(A->right, B->right);
    }
};

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
        if(ptr != number.end()) {
            node->left = new TreeNode(*ptr);
            nodeQueue.push(node->left);
        }

        if(ptr == number.end())
            break;

        ptr++;
        if(ptr != number.end())
        {
            node->right = new TreeNode(*ptr);
            nodeQueue.push(node->right);
        }
    }

    return root;
}

int main() {
    /// 数据生成 ptr
    vector<int> A = {3,4,5,1,2};
    vector<int> B = {4,1};

    TreeNode* treeA = createTree(A);
    TreeNode* treeB = createTree(B);

    Solution solve;
    string result = solve.isSubStructure(treeA, treeB) ? "True" : "False";
    cout << "result: " << result << endl;

    cout << "\nFinish" << endl;
    return 0;
}
