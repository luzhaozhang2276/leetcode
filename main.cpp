#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "[]";

        string res = "[";
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if (node != nullptr)
            {
                res += std::to_string(node->val) + ',';
                que.push(node->left);
                que.push(node->right);
            } else
                res += "NULL,";
        }

        *(res.end()-1) = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]")
            return nullptr;

        vector<string> values;      // 存为string不会面临 int 的 NULL 判断问题,但是占用空间更大
        istringstream iss(data.substr(1, data.size()-2));
        string tmp;
        while (getline(iss, tmp, ','))
            values.push_back(tmp);

        auto* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if (values[i] != "NULL") {
                node->left = new TreeNode(stoi(values[i]));
                que.push(node->left);
            }
            i++;
            if (values[i] != "NULL") {
                node->right = new TreeNode(stoi(values[i]));
                que.push(node->right);
            }
            i++;
        }

        return root;
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
        if(ptr != number.end() && *ptr != -100) {
            node->left = new TreeNode(*ptr);
            nodeQueue.push(node->left);
        }

        if(ptr == number.end())
            break;

        ptr++;
        if(ptr != number.end() && *ptr != -100)
        {
            node->right = new TreeNode(*ptr);
            nodeQueue.push(node->right);
        }
    }

    return root;
}

int main() {
    // vector<int> num = {1,2,3,NULL,NULL,4,5};
    vector<int> num = {-1,0,1};
    TreeNode* tree = createTree(num);

    Codec solve;
    cout << solve.serialize(tree) << endl;
    TreeNode* root = solve.deserialize(solve.serialize(tree));

    cout << "\nFinish";
    return 0;
}
