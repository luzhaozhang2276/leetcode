#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create (vector<int>& nums) {
    auto *list = new ListNode(0);
    ListNode *ptr = list;
    for (auto &p:nums)
    {
        ptr->next = new ListNode(p);
        ptr = ptr->next;
    }

    ptr = list->next;
    delete list;
    return ptr;
}

/// 24. 两两交换链表中的节点

#if 0
/// 迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0,head);
        ListNode *ptr = dummyHead;
        while (ptr->next != nullptr && ptr->next->next != nullptr) {
            ListNode *p1 = ptr->next;
            ListNode *p2 = ptr->next->next;

            ptr->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            ptr = p1;
        }
        return dummyHead->next;
    }
};

#elif 1
/// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *ptr = head->next;
        head->next = swapPairs(ptr->next);
        ptr->next = head;

        return ptr;
    }
};

#endif

int main() {
    vector<int> nums = {1,2,3,4,5};

    Solution solve;
    auto p = solve.swapPairs(create(nums));
    while (p != nullptr) {
        cout << p->val << " -> ";
        p = p->next;
    }

    cout << "\nFinish";
    return 0;
}