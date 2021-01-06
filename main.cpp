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

        deque<TreeNode*> queTree;
        queTree.push_back(root);

        while (!queTree.empty())
        {
            vector<int> curr;
            TreeNode* pNode;
            for (int i = queTree.size(); i > 0; --i)
            {
                if (! (res.size() & 1))     // 位运算判断奇偶
                {
                    pNode = queTree.front();
                    queTree.pop_front();
                    curr.push_back(pNode->val);
                    if (pNode->left)
                        queTree.push_back(pNode->left);
                    if (pNode->right)
                        queTree.push_back(pNode->right);
                } else {
                    pNode = queTree.back();
                    queTree.pop_back();
                    curr.push_back(pNode->val);
                    if (pNode->right)
                        queTree.push_front(pNode->right);
                    if (pNode->left)
                        queTree.push_front(pNode->left);
                }
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
    vector<int> num = {1,2,3,4,NULL,NULL,5};
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
