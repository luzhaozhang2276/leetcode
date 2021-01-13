#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

#if 1
/// 哈希表法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        // 初始化
        Node* cur = head;
        unordered_map<Node*, Node*> map;

        // 复制链表
        while (cur != nullptr)
        {
            // first:原节点    second:键值(新节点)
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;

        // 构建新链表的next和random指向
        while (cur != nullptr)
        {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        // 返回值
        return map[head];
    }
};

#elif 1
/// 拼接 && 拆分
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* cur = head;
        // clone
        while (cur != nullptr)
        {
            Node* clone = new Node(cur->val);
            clone->next = cur->next;
            cur->next = clone;
            cur = clone->next;
        }

        // link random
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // split
        cur = head->next;
        Node *pre = head, *res = head->next;
        while (cur->next != nullptr)
        {
            pre->next = cur->next;
            cur->next = pre->next->next;
            pre = pre->next;
            cur = cur->next;
        }

        pre->next = nullptr;
        return res;
    }
};
#endif


int main() {
    /// 数据生成
    vector<int> values = {7,13,11,10,1};
    vector<int> rands = {-1, 0, 4, 2, 0};

    vector<Node*> vec;
    for (auto p:values)
    {
        Node* node;
        node = new Node(p);
        vec.push_back(node);
    }
    vec.push_back(new Node(0));

    for (int i = 0; i < vec.size()-1; ++i)
    {
        vec[i]->next = vec[i+1];
        if (rands[i] != -1)
            vec[i]->random = vec[rands[i]];
        else
            vec[i]->random = nullptr;
    }

    vec.pop_back();
    vec.back()->next = nullptr;

    Node* head = vec[0];

    /// 复制操作
    Solution solve;
    solve.copyRandomList(head);

    cout << "\nFinish";
    return 0;
}
