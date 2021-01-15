#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        pre = nullptr;

        recur(root);
        head->left = pre;
        pre->right = head;

        return head;
    }

    void recur(Node *cur)
    {
        // 递归终止条件
        if (cur == nullptr)
            return;

        // 左子树
        recur(cur->left);

        // 根节点
        if (pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;

        // 右子树
        recur(cur->right);
    }

private:
    Node *pre, *head;
};

/// 生成二叉树: 使用队列(先进先出)
Node* createTree(vector<int> &number)
{
    if (number.empty())
        return nullptr;

    auto ptr = number.begin();

    Node* root = new Node(*ptr);
    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    while (ptr != number.end())
    {
        Node* node = nodeQueue.front();
        nodeQueue.pop();

        ptr++;
        if(ptr != number.end() && *ptr != '\0') {
            node->left = new Node(*ptr);
            nodeQueue.push(node->left);
        }

        if(ptr == number.end())
            break;

        ptr++;
        if(ptr != number.end() && *ptr != '\0')
        {
            node->right = new Node(*ptr);
            nodeQueue.push(node->right);
        }
    }

    return root;
}

int main() {
    vector<int> num = {4,2,5,1,3};
    Node* tree = createTree(num);

    Solution solve;
    auto ptr = solve.treeToDoublyList(tree);

    cout << "\nFinish";
    return 0;
}
