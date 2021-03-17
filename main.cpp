#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* root (vector<int>& nums) {
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

/// 21. 合并两个有序链表
#if 0
/// 循环
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);      // 伪头结点
        auto ptr = &dummy;
        while (l1 && l2) {
            ptr->next = (l1->val > l2->val) ? l2 : l1;
            (l1->val > l2->val) ? (l2 = l2->next) : (l1 = l1->next);
            ptr = ptr->next;
        }
        ptr->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

#elif 1
/// 递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
#endif


int main() {
    vector<int> nums1 {1,2,4};
    vector<int> nums2 {1,3,4};
    auto ptr1 = root(nums1);
    auto ptr2 = root(nums2);

    Solution solve;
    auto ptr = solve.mergeTwoLists(ptr1, ptr2);

    cout << "\nFinish";
    return 0;
}