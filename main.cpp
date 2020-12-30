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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root)
            return res;

        queue<TreeNode*> queTree;
        queTree.push(root);


        while (!queTree.empty())
        {
            vector<int> curr;
            for (int i = queTree.size(); i > 0; --i)
            {
                TreeNode* pNode = queTree.front();
                queTree.pop();
                curr.push_back(pNode->val);
                if (pNode->left)
                    queTree.push(pNode->left);
                if (pNode->right)
                    queTree.push(pNode->right);
            }

            res.push_back(curr);
        }
        return res;
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
    vector<int> num = {3,9,20,NULL,NULL,15,7};
    TreeNode* tree = createTree(num);

    Solution solve;
    for (auto p:solve.levelOrder(tree)) {
        for (auto q:p)
            cout << q << " ";
        cout << endl;
    }


    cout << "\nFinish";
    return 0;
}
