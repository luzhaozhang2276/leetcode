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

/// NC4. 判断链表中是否有环

/// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};


int main() {
    vector<int> nums {1,2,3,4,5};
    auto ptr = root(nums);

    ListNode* head = ptr;
    while (ptr->next != nullptr)
        ptr = ptr->next;

//    ptr->next = head->next->next;

    Solution solve;
    cout << "res : " << solve.hasCycle(head) << endl;

    cout << "\nFinish";
    return 0;
}