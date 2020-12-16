#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
/// 快慢双指针
class Solution {
public:
    ListNode* findLoopEntrance(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != nullptr && fast != slow);

        if (fast == nullptr)
            return nullptr;

        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};

#elif 1
/// 哈希表
class Solution {
public:
    ListNode* findLoopEntrance(ListNode* head) {
        unordered_set<ListNode*> st;
        while (head)
        {
            if (st.find(head) == st.end())
            {
                st.insert(head);
                head = head->next;
            } else
                return head;
        }

        return nullptr;
    }
};

#endif

int main() {
    /// 数据生成 ptr
    vector<int> number = {1,2,3,4,5,6};
    int numberLoop = 0;

    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:number)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    if (numberLoop > 0)
    {
        ListNode *pLoop = list;
        for (int i = 0; i < numberLoop; ++i)
            pLoop = pLoop->next;

        ptr->next = pLoop;
    }

    ptr = list->next;
    delete list;

    /// 数据处理
    Solution solve;

    auto p = solve.findLoopEntrance(ptr);
    if (p != nullptr)
        cout << "Entrance: " << p->val << endl;
    else
        cout << "No loop" << endl;

    cout << "\nFinish" << endl;
    return 0;
}
