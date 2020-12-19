#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
/// 双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
//        ListNode* pNext;
        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        return pre;
    }
};

#elif 0
/// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);
    }

private:
    ListNode* recur(ListNode* cur, ListNode* pre) {
        if (cur == nullptr)     // 终止条件
            return pre;

        // 递归调用
        ListNode* res = recur(cur->next, cur);
        cur->next = pre;
        return res;
    }
};

#elif 1
/// 堆栈
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> s;
        while (head != nullptr)
        {
            s.push(head);
            head = head->next;
        }

        if (s.empty())
            return nullptr;

        ListNode* res = s.top();
        s.pop();
        ListNode* tmp = res;
        while (!s.empty())
        {
            tmp->next = s.top();
            s.pop();
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        return res;
    }

};

#endif

int main() {
    /// 数据生成 ptr
    vector<int> number = {1,2,3,4,5,6};

    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:number)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    ptr = list->next;
    delete list;

    cout << "initial: ";
    auto print = ptr;
    while (print != nullptr)
    {
        cout << print->val << " ";
        print = print->next;
    }
    cout << endl;

    /// 数据处理
    Solution solve;

    auto p = solve.reverseList(ptr);
    if (p != nullptr)
    {
        cout << "reverse: ";
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }

    }
    else
        cout << "list empty" << endl;

    cout << "\nFinish" << endl;
    return 0;
}
