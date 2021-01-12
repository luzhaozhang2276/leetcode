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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return res;

        currSum = sum;
        recur(root);

        return res;
    }

    void recur(TreeNode* root) {
        // 递归终止条件
        // 递归过程中,遇到满足条件的路径,则记录保存,运行结束后输出保存结果即可
        if (root == nullptr)
            return;

        currSum -= root->val;
        curr.push_back(root->val);

        // 叶子节点 && 路径和满足
        if ((root->left == nullptr) && (root->right == nullptr) && currSum == 0)
            res.push_back(curr);

        if (root->left != nullptr)
            recur(root->left);
        if (root->right != nullptr)
            recur(root->right);

        // 回退
        currSum += curr.back();
        curr.pop_back();
    }

private:
    vector<vector<int>> res;
    vector<int> curr;
    int currSum;
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
    vector<int> num = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    TreeNode* tree = createTree(num);

    Solution solve;
    vector<vector<int>> res = solve.pathSum(tree, 22);

    for (const auto& p:res)
    {
        for (auto q:p)
            cout << q << " ";
        cout << endl;
    }


    cout << "\nFinish";
    return 0;
}
