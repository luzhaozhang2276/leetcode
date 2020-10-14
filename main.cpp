#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}     // 构造函数
};

class Solution {
public:
    std::vector<int> res;
    vector<int> reversePrint(ListNode* head) {

#if 1   // 入栈法
        // std::stack<ListNode*> nodes;     // 只需要保存val即可,即stack<int>
        stack<int> values;
        while (head)
        {
            values.push(head->val);
            head = head->next;
        }

        while(!values.empty())
        {
            res.push_back(values.top());
            values.pop();
        }
#elif 0 // reverse法
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
#elif 0 // 递归法
        if(!head)
            return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
#elif 0 // 改变链表结构法
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        while (pre)
        {
            res.push_back(pre->val);
            pre = pre->next;
        }
#endif
        return res;
    }
};
/**
 * @brief 4种方法:reverse反转法,堆栈法,递归法,改变链表结构法
 * @note
 */
int main() {
    // 头插法
    vector<int> init{2,3,1};
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->next = nullptr;
    for(auto ptr:init)
    {
        ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        p->val = ptr;
        p->next = nullptr;
        if(!head->next)
            head->next = p;
        else
        {
            p->next = head->next;
            head->next = p;
        }
    }

    cout << "print init list" << endl;
    ListNode* p = head;
    while(p->next)
    {
        cout << p->next->val << endl;
        p = p->next;
    }

    cout << "\nprint new list" << endl;
    Solution s;
    vector<int> result(s.reversePrint(head->next));     /// leetcode 中,单链表的头指针对应的是头结点
    for(auto ptr:result)
        cout << ptr << endl;

    cout << "\nFinish" << endl;
    return 0;
}
